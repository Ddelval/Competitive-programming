//  D.cpp
//  Created by David del Val on 09/09/2021
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
class SimpleSegTree {
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
        }
    }

public:
    SimpleSegTree(int size) : size(size), tree(size, 0) {
        _build(1, 0, size - 1);
    }
    T query(int l, int r) {
        ql = l;
        qr = r;
        return query(1, 0, size - 1);
    }
    void updatePoint(int pos, int val) {
        upos = pos;
        uvalue = val;
        _update(1, 0, size - 1);
    }
};

/*
const ll zero = 0;
auto inizero = [](int index) { return 0ll; };
        auto mergesum = [](ll a, ll b) { return a + b; };
        auto updateInc = [](ll a, ll b) { return a + b; };
        SimpleSegTree<ll, mergesum, inizero, updateInc, zero> vertST(n),
            horST(m);
*/

ll countTimes(vi horizontal, unordered_map<int, int> toHindex,
              vector<vi> horizontalInVertical) {

    vl belowRoad(horizontal.size() + 1, 0);
    ll ans = 0;

    for (int i = 0; i < horizontalInVertical.size(); ++i) {
        if (horizontalInVertical[i].size() == 0) {
            continue;
        }
        for (auto pos : horizontalInVertical[i]) {
            auto it = upper_bound(all(horizontal), pos);
            if (it == horizontal.end()) {
                ans += belowRoad.back();
            } else {
                ans += belowRoad[it - horizontal.begin()];
            }
        }
        for (auto pos : horizontalInVertical[i]) {
            auto it = upper_bound(all(horizontal), pos);
            if (it == horizontal.end()) {
                belowRoad.back()++;
            } else {
                belowRoad[it - horizontal.begin()]++;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi vertical = readVector<int>(n);
        vi horizontal = readVector<int>(m);
        sort(all(vertical));
        sort(all(horizontal));

        unordered_map<int, int> toVIndex;
        for (int i = 0; i < n; ++i) {
            toVIndex[vertical[i]] = i;
        }
        unordered_map<int, int> toHIndex;
        for (int i = 0; i < m; ++i) {
            toHIndex[horizontal[i]] = i;
        }
        vector<vi> horizontalInVertical(n, vi());
        vector<vi> verticalInHorizontal(m, vi());

        while (k--) {
            int a, b;
            cin >> a >> b;
            if (toVIndex.count(a) && toHIndex.count(b)) {
                continue;
            } else if (toVIndex.count(a)) {
                horizontalInVertical[toVIndex[a]].pb(b);
            } else {
                verticalInHorizontal[toHIndex[b]].pb(a);
            }
        }
        cout << countTimes(horizontal, toHIndex, horizontalInVertical) +
                    countTimes(vertical, toVIndex, verticalInHorizontal)
             << "\n";
    }

    return 0;
}