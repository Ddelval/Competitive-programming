//  D1.cpp
//  Created by David del Val on 12/09/2021
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
template <typename T, T (*merge)(T, T), T (*initialize)(int),
          T (*update_op)(T, T), const T &neutral>
struct SimpleSegTree {
    int size;
    vector<T> tree;
    int ql, qr, uvalue, upos;

    void _build(int current, int l, int r) {
        if (l == r) {
            tree[current] = initialize(l);
        } else {
            int mid = (l + r) >> 1;
            _build(current << 1, l, mid);
            _build(current << 1 | 1, mid + 1, r);
            tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
        }
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
    void _update(int current, int l, int r) {
        if (l == r) {
            tree[current] = update_op(tree[current], uvalue);
        } else {
            int mid = (l + r) >> 1;
            if (upos <= mid) {
                _update(current << 1, l, mid);
            } else {
                _update(current << 1 | 1, mid + 1, r);
            }
            tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
        }
    }

public:
    SimpleSegTree(int siz) : size(siz), tree(4 * size, 0) {
        _build(1, 0, size - 1);
    }
    T query(int l, int r) {
        ql = l;
        qr = r;
        return _query(1, 0, size - 1);
    }
    void updatePoint(int pos, int val) {
        upos = pos;
        uvalue = val;
        _update(1, 0, size - 1);
    }
};

const ll zero = 0;
ll merg(ll a, ll b) { return a + b; }
ll initialize(int index) { return 0ll; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vii elems;
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            elems.pb({a, i});
        }
        sort(all(elems), [](pii a, pii b) {
            if (a.fi != b.fi) {
                return a.fi < b.fi;
            } else {
                return a.se > b.se;
            }
        });
        echo(elems);
        vi order(m);
        for (int i = 0; i < m; ++i) {
            order[i] = elems[i].se;
        }
        SimpleSegTree<ll, merg, initialize, merg, zero> segTree(m);
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            if (order[i]) {
                ans += segTree.query(0, order[i] - 1);
            }
            segTree.updatePoint(order[i], 1);
        }
        cout << ans << "\n";
    }

    return 0;
}