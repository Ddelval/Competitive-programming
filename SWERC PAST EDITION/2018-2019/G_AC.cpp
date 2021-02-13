//  G.cpp
//  Created by David del Val on 12/02/2021
//
//

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p);

// ====================================================== //
// ===================  Container IO  =================== //
// ====================================================== //
template <bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;
struct subs_fail {};

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <>
struct Has_iterator<string> : subs_fail {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
    vector<T> v;
    v.reserve(size);
    T a;
    for (int i = 0; i < size; ++i) {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

// ====================================================== //
// ================== Pairs operations ================== //
// ====================================================== //
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
ll mod = 1000000007ll;

int n, m;
string sbase;
vl prefixsum;

struct node {
    node *left, *right;
    ll length;
    ll value;
    bool leaf = false;
    ll l; // for the leaves, index of the first char in the base
};
map<int, node *> nodes;

node *add_append_node(node *left, node *right) {
    node *n = new node();
    n->left = left;
    n->right = right;
    n->value = (n->left->value + n->right->value) % mod;
    n->length = n->left->length + n->right->length;
    return n;
}

void split_leaf(node *n, ll pos) {
    //cout << n->l << " " << n->length << " " << pos << endl;
    node *left = new node();
    left->leaf = true;
    left->value = prefixsum[n->l + pos] - prefixsum[n->l];
    left->l = n->l;
    left->length = pos;

    node *right = new node();
    right->leaf = true;
    right->value = prefixsum[n->l + n->length] - prefixsum[n->l + pos];
    right->l = n->l + pos;
    right->length = n->length - pos;

    n->leaf = false;
    n->left = left;
    n->right = right;
}

node *get_subrange(node *n, ll left, ll right) {
    if (right > n->length) {
        right = n->length;
    }
    if (left < 0) {
        left = 0;
    }

    if (left == 0 && right == n->length) {
        return n;
    }
    if (right <= left) {
        return NULL;
    }

    if (n->leaf) {
        if (left == 0) {
            split_leaf(n, right);
            return n->left;
        }
        if (right == n->length) {
            split_leaf(n, left);
            return n->right;
        }
        split_leaf(n, left);
        split_leaf(n->right, right - n->left->length);
        return n->right->left;
    }

    node *n1 = get_subrange(n->left, left, right);
    node *n2 = get_subrange(n->right, left - n->left->length, right - n->left->length);
    if (n1 != NULL && n2 != NULL) {
        return add_append_node(n1, n2);
    } else if (n1 != NULL) {
        return n1;
    } else if (n2 != NULL) {
        return n2;
    }
    abort();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> sbase;
    m = sbase.length();

    string s;
    ll a1, a2, a3;

    prefixsum = vl(m + 1);
    prefixsum[0] = 0;
    for (int i = 0; i < m; ++i) {
        prefixsum[i + 1] = prefixsum[i] + ll(sbase[i]);
        prefixsum[i + 1] %= mod;
    }

    node *n0 = new node();
    n0->leaf = true;
    n0->l = 0;
    n0->length = sbase.length();
    n0->value = prefixsum[m];
    nodes[0] = n0;

    node *empty = new node();
    empty->leaf = true;
    empty->l = 0;
    empty->length = 0;
    empty->value = 0;

    for (int i = 1; i < n; ++i) {
        cin >> s;
        if (s == "SUB") {
            cin >> a1 >> a2 >> a3;
            if (a2 == a3) {
                nodes[i] = empty;
            } else {
                node *n1 = get_subrange(nodes[a1], a2, a3);
                nodes[i] = n1;
            }

        } else {
            cin >> a1 >> a2;
            node *n = add_append_node(nodes[a1], nodes[a2]);
            nodes[i] = n;
        }
    }
    cout << nodes[n - 1]->value << "\n";

    return 0;
}