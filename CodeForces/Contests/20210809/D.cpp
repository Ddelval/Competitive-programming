//  D.cpp
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
int n, m;

const int lim = 6e5;
pii tree[4 * lim], lazy[4 * lim];
constexpr pii nil = {0, -1};
int qr, ql;
pii qValue;
int inde;
template <typename T, T (*merge)(T, T), T (*initialize)(int), const T &neutral>
class SegTree {
    int n;
    int ql, qr;
    T qValue;
    vector<T> tree;
    vector<T> lazy;

    void _build(int current, int l, int r) {
        lazy[current] = nil;
        if (l == r) {
            tree[current] = initialize(l);
        } else {
            int mid = (l + r) >> 1;
            _build(current << 1, l, mid);
            _build(current << 1 | 1, mid + 1, r);
            tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
        }
    }
    void push_down(int current) {
        if (lazy[current] == neutral) {
            return;
        }
        tree[current << 1] = merge(tree[current << 1], lazy[current]);
        tree[current << 1 | 1] = merge(tree[current << 1 | 1], lazy[current]);
        lazy[current << 1] = merge(lazy[current << 1], lazy[current]);
        lazy[current << 1 | 1] = merge(lazy[current << 1 | 1], lazy[current]);
        lazy[current] = neutral;
    }
    T _query(int current, int l, int r) {
        if (l > qr || r < ql) {
            return neutral;
        }
        if (l >= ql && r <= qr) {
            return tree[current];
        }
        push_down(current);
        int mid = (l + r) >> 1;
        T n1 = _query(current << 1, l, mid);
        T n2 = _query(current << 1 | 1, mid + 1, r);
        return merge(n1, n2);
    }

    void _update(int current, int l, int r) {
        if (l > qr || r < ql) {
            return;
        }
        if (l >= ql && r <= qr) {
            tree[current] = merge(tree[current], qValue);
            lazy[current] = merge(lazy[current], qValue);
            return;
        }
        push_down(current);
        int mid = (l + r) >> 1;
        _update(current << 1, l, mid);
        _update(current << 1 | 1, mid + 1, r);
        tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
    }

public:
    SegTree(int actualSize) : n(actualSize), tree(4 * n), lazy(4 * n) {
        _build(1, 0, n - 1);
    }
    T query(int l, int r) {
        ql = l;
        qr = r;
        return _query(1, 0, n - 1);
    }
    void update(int l, int r, T value) {
        ql = l;
        qr = r;
        qValue = value;
        _update(1, 0, n - 1);
    }
};
pii merge(pii a, pii b) { return max(a, b); }
pii initialize(int elem) { return make_pair(0, -1); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int cline, l, r;
    set<int> coords;
    vector<pair<int, pii>> segments;
    segments.reserve(m);

    for (int i = 0; i < m; ++i) {
        cin >> cline >> l >> r;
        segments.pb({cline - 1, {l, r}});
        coords.insert(l);
        coords.insert(r);
    }
    unordered_map<int, int> translate;
    inde = 0;
    for (auto elem : coords) {
        translate[elem] = inde++;
    }
    vector<vector<pii>> rowSegments(n);
    for (int i = 0; i < m; ++i) {
        rowSegments[segments[i].fi].pb(
            {translate[segments[i].se.fi], translate[segments[i].se.se]});
    }
    echo(rowSegments);
    SegTree<pii, merge, initialize, nil> seg(inde);
    vi prev(n, -1);
    for (int i = 0; i < n; ++i) {
        pii mx = nil;
        for (auto interval : rowSegments[i]) {
            mx = max(mx, seg.query(interval.fi, interval.se));
        }
        echo(mx);
        prev[i] = mx.se;
        mx.fi++;
        mx.se = i;
        for (auto interval : rowSegments[i]) {
            seg.update(interval.fi, interval.se, mx);
        }
    }
    pii fin = seg.query(0, inde - 1);
    echo(fin);
    vector<bool> visited(n);
    int cur = fin.se;
    while (cur != -1) {
        visited[cur] = true;
        cur = prev[cur];
    }
    cout << n - fin.fi << "\n";
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}