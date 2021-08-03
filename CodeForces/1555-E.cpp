//  1555-E.cpp
//  Created by David del Val on 31/07/2021
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
#else
#define db(x)
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
class SegTree {
    struct node {
        int value, lazy;
    };
    struct qdata {
        int l, r;
        int diff;
    };

    node *nodes;
    qdata query;
    int n;

    void build(int current, int l, int r) {
        nodes[current].value = 0;
        nodes[current].lazy = 0;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(current << 1, l, mid);
        build(current << 1 | 1, mid + 1, r);
    }

    void propagate(int current) {
        nodes[current << 1].lazy += nodes[current].lazy;
        nodes[current << 1 | 1].lazy += nodes[current].lazy;

        nodes[current << 1].value += nodes[current].lazy;
        nodes[current << 1 | 1].value += nodes[current].lazy;
        nodes[current].lazy = 0;
    }
    void recalculate(int current) {
        nodes[current].value =
            std::min(nodes[current << 1].value, nodes[current << 1 | 1].value);
    }

    void _update(int current, int l, int r) {
        db(cout << "up: " << current << " " << l << " " << r << endl);
        if (l > query.r || r < query.l) {
            return;
        }
        if (l >= query.l && r <= query.r) {
            nodes[current].value += query.diff;
            nodes[current].lazy += query.diff;
            return;
        }
        propagate(current);
        int mid = (l + r) >> 1;
        _update(current << 1, l, mid);
        _update(current << 1 | 1, mid + 1, r);
        recalculate(current);
    }

public:
    SegTree(int m) : n(m) {
        nodes = new node[4 * m];
        build(1, 0, n - 1);
    }
    ~SegTree() { delete[] nodes; }

    void update(int l, int r, int diff) {
        query.l = l;
        query.r = r;
        query.diff = diff;
        _update(1, 0, n - 1);
    }
    int min() { return nodes[1].value; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    SegTree stree(m - 1);
    vector<pair<pii, int>> segments(n);
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        a--, b -= 2;
        segments[i] = {{a, b}, c};
    }
    sort(all(segments),
         [](pair<pii, int> a, pair<pii, int> b) { return a.se < b.se; });

    int j = 0;
    ll ans = inf;
    // cout << segments << endl;
    for (int i = 0; i < n; ++i) {
        while (j < segments.size() && stree.min() == 0) {
            stree.update(segments[j].fi.fi, segments[j].fi.se, 1);
            j++;
        }
        if (stree.min() != 0) {

            // cout << i << " " << j << " " << stree.min() << endl;
            ans = min(ans, (ll)segments[j - 1].se - segments[i].se);
        }
        stree.update(segments[i].fi.fi, segments[i].fi.se, -1);
    }
    cout << ans << "\n";

    return 0;
}