//  0515-E.cpp
//  Created by David del Val on 10/08/2021
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

const int lim = 1e5 + 10;
vi edges, heights;
struct node {
    ll pre, pos, edges, val;
    ll redge;
};
ostream &operator<<(ostream &o, node &n) {
    o << "(" << n.pre << " " << n.pos << " " << n.edges << " " << n.val << " "
      << n.redge << ")";
    return o;
}
constexpr node nil = {-1, -1, -1, -1, -1};

node initialize(int position) {
    ll h = heights[position];
    return {h, h, 0, h, edges[position]};
}

node merge(node nl, node nr) {
    if (nl.val == -1) {
        return nr;
    }
    if (nr.val == -1) {
        return nl;
    }

    ll pre, pos, edges, val, redge;
    redge = nr.redge;
    pre = max(nl.pre + nl.redge + nr.edges, nr.pre);
    pos = max(nl.pos, nl.edges + nl.redge + nr.pos);
    edges = nl.edges + nr.edges + nl.redge;

    val = max(nl.val, nr.val);
    val = max(val, nl.pre + nl.redge + nr.pos);

    return {pre, pos, edges, val, redge};
}
template <typename T, T (*merge)(T, T), T (*initialize)(int), const T &neutral>
class SegTree {
private:
    int n; // Size
    int ql, qr;
    vector<T> tree;

    void _build(int current, int l, int r) {
        if (l == r) {
            tree[current] = initialize(l);
        } else {
            int mid = (l + r) >> 1;
            _build(current << 1, l, mid);
            _build(current << 1 | 1, mid + 1, r);
            tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
        }
        db(cout << l << " " << r << ": " << tree[current] << endl);
    }

    T _query(int current, int l, int r) {
        if (l > qr || r < ql) {
            return neutral;
        }
        if (l >= ql && r <= qr) {
            return tree[current];
        }
        int mid = (l + r) >> 1;
        T n1 = _query(current << 1, l, mid);
        T n2 = _query(current << 1 | 1, mid + 1, r);
        return merge(n1, n2);
    }

public:
    SegTree(int actualSize) : n(actualSize), tree(4 * n) {
        _build(1, 0, n - 1);
    }
    T query(int l, int r) {
        ql = l;
        qr = r;
        return _query(1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    edges = vi(2 * n);
    heights = vi(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> edges[i];
        edges[n + i] = edges[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
        heights[i] *= 2;
        heights[n + i] = heights[i];
    }
    SegTree<node, merge, initialize, nil> sTree(2 * n);
    auto qTree = [&sTree](int l, int r) {
        if (r < l) {
            return -1ll;
        }
        node n = sTree.query(l, r);
        return n.val;
    };
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ll res = 0;
        if (a <= b) {
            res = max(res, qTree(0, a - 1));
            res = max(res, qTree(b + 1, n + a - 1));
        } else {
            res = max(res, qTree(b + 1, a - 1));
        }
        cout << res << "\n";
    }

    return 0;
}