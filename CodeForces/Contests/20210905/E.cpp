//  E.cpp
//  Created by David del Val on 05/09/2021
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

#ifdef DEBUG
#define db(x) x
#define echo(x) cout << #x << ": " << x << endl;
#else
#define db(x)
#define echo(x)
#endif

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

template <typename T> struct subs_succeeded : std::true_type {};
template <> struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T> struct get_iter_res {
private:
    template <typename X> static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <> struct Has_iterator<string> : subs_fail {};

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T> struct get_termination {
    static constexpr const char *get() { return sep1; }
};
template <typename U, typename S> struct get_termination<vector<U, S>> {
    static constexpr const char *get() { return sep2; }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator =
                get_termination<typename T::value_type>::get();
            o << terminator;
        }
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll> inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) { return {a.fi + b.fi, a.se + b.se}; }

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

// gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
// Local constraints

#else
// Judge constraints
#endif

struct node {
    ll count = 1;
    ll len = 1;
    ll sufixLen = 1, sufixVal;
    ll prefixLen = 1, prefixVal;

    node() {}
    node(int val) : sufixVal(val), prefixVal(val) {}

    static node nil() {
        node n;
        n.len = -1;
        return n;
    }
};
ostream &operator<<(ostream &o, node &n) {
    o << "(" << n.count << ", " << n.len << ", " << n.sufixLen << ", "
      << n.sufixVal << ", " << n.prefixLen << ", " << n.prefixVal << ")";
    return o;
}

node merge(node left, node right) {
    if (left.len == -1) {
        return right;
    }
    if (right.len == -1) {
        return left;
    }

    node result;
    result.count = left.count + right.count;
    if (right.sufixLen == right.len && left.sufixVal <= right.prefixVal) {
        result.sufixLen = right.len + left.sufixLen;
    } else {
        result.sufixLen = right.sufixLen;
    }
    if (left.prefixLen == left.len && left.sufixVal <= right.prefixVal) {
        result.prefixLen = left.len + right.prefixLen;
    } else {
        result.prefixLen = left.prefixLen;
    }

    result.len = right.len + left.len;
    result.sufixVal = right.sufixVal;
    result.prefixVal = left.prefixVal;

    if (left.sufixVal <= right.prefixVal) {
        result.count += left.sufixLen * right.prefixLen;
    }

    echo(left);
    echo(right);
    echo(result);

    return result;
}

const int lim = 2e5;
node tree[4 * lim];
int datt[lim];

void build(int current, int l, int r) {
    if (l == r) {
        tree[current] = node(datt[l]);
    } else {
        int mid = (l + r) >> 1;
        build(current << 1, l, mid);
        build(current << 1 | 1, mid + 1, r);
        tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
    }
}

int ql, qr;
node query(int current, int l, int r) {
    if (l > qr || r < ql) {
        return node::nil();
    }
    if (l >= ql && r <= qr) {
        return tree[current];
    }
    int mid = (l + r) >> 1;
    node n1 = query(current << 1, l, mid);
    node n2 = query(current << 1 | 1, mid + 1, r);
    return merge(n1, n2);
}
int upos, uval;
void update(int current, int l, int r) {
    if (l == r) {
        tree[current] = node(uval);
    } else {
        int mid = (l + r) >> 1;
        if (upos <= mid) {
            update(current << 1, l, mid);
        } else {
            update(current << 1 | 1, mid + 1, r);
        }
        tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> datt[i];
    }
    build(1, 0, n - 1);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> upos >> uval;
            upos--;
            update(1, 0, n - 1);
        } else {
            cin >> ql >> qr;
            ql--, qr--;
            cout << query(1, 0, n - 1).count << "\n";
        }
    }

    return 0;
}