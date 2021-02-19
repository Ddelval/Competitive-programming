//  J.cpp
//  Created by David del Val on 18/02/2021
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

const int lim = 1e6 + 10;
int n;
int arr[lim];
struct node {
    int mval, occurr;
    int left, right;
};

node tree[4 * lim];

node mergenodes(node n1, node n2) {
    n1.right = n2.right;
    n2.left = n1.left;
    if (n1.mval < n2.mval) {
        return n1;
    } else if (n1.mval > n2.mval) {
        return n2;
    } else {
        n1.occurr += n2.occurr;
        return n1;
    }
}

const node build_tree(int cnode, int left, int right) {
    if (left == right) {
        //cout << cnode << endl;
        tree[cnode] = {arr[left], 1, left, right};
    } else {
        int mid = (left + right) / 2;
        tree[cnode] = mergenodes(build_tree(cnode * 2, left, mid), build_tree(cnode * 2 + 1, mid + 1, right));
    }
    //cout << cnode << " " << tree[cnode].occurr << endl;
    return tree[cnode];
}

const node search(int cnode, int left, int right) {
    //cout << "exploring" << cnode << endl;
    if (left > tree[cnode].right || right < tree[cnode].left) {
        // No intersection
        return {iinf, 0, tree[cnode].right, tree[cnode].left};
    } else if (left <= tree[cnode].left && right >= tree[cnode].right) {
        return tree[cnode];
    }
    return mergenodes(search(cnode * 2, left, right), search(cnode * 2 + 1, left, right));
}

ll mod = 1000000007;
ll factorial[2 * lim];
void intialize() {
    factorial[0] = 1;
    for (int i = 1; i < 2 * lim; ++i) {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

ll power(ll base, ll exp) {
    if (exp == 0) {
        return 1;
    }
    ll res = power(base, exp / 2);
    res = (res * res) % mod;
    if (exp % 2) {
        res *= base;
    }
    return res % mod;
}

ll inverse(ll num) {
    return power(num, mod - 2);
}

ll getCatalan(ll n) {
    ll r1 = factorial[2 * n];
    ll r2 = ((n + 1) * factorial[n]) % mod;
    r2 = (r2 * factorial[n]) % mod;
    //cout << r1 << " " << r2 << " " << inverse(r2) << endl;
    return (r1 * inverse(r2)) % mod;
}

unordered_map<int, vi> positions;

ll getProduct(int left, int right) {

    node a = search(1, left, right);
    ll res = getCatalan(a.occurr);

    int num = a.mval;
    vi &elempos = positions[num];
    auto it1 = lower_bound(all(elempos), left);
    auto it2 = upper_bound(all(elempos), right);
    if (*it1 > right)
        return res;

    int ipos = left;
    for (auto it3 = it1; it3 != it2; it3++) {
        if (*it3 > ipos) {
            res = (res * getProduct(ipos, *it3 - 1)) % mod;
        }
        ipos = *it3 + 1;
    }
    if (ipos <= right) {
        res = (res * getProduct(ipos, right)) % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intialize();

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (!n) {
        cout << "1\n";
        return 0;
    }
    //cout << arr << endl;

    for (int i = 0; i < n; ++i) {
        positions[arr[i]].pb(i);
    }
    build_tree(1, 0, n - 1);
    cout << getProduct(0, n - 1) << "\n";

    return 0;
}