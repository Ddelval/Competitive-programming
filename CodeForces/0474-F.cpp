//  0474-F.cpp
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

// mi(0, n) = n
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
vl datt;
struct node {
    ll mi, elem;
};
node tree[4*lim];

node merge(node n1, node n2) {
    if (n1.mi == n2.mi) {
        return {n1.mi, n1.elem + n2.elem};
    } else if (n1.mi < n2.mi) {
        return n1;
    } else {
        return n2;
    }
}

void build(int cnode, int l, int r) {
    if (l == r) {
        tree[cnode] = {datt[l], 1};
    } else {
        int mid = (l + r) >> 1;
        build(cnode << 1, l, mid);
        build(cnode << 1 | 1, mid + 1, r);
        tree[cnode] = merge(tree[cnode << 1], tree[cnode << 1 | 1]);
    }
}
struct quer {
    int l, r;
} q;

node query(int cnode, int l, int r) {
    if (l > q.r || r < q.l) {
        return {inf, 0};
    }
    if (l >= q.l && r <= q.r) {
        return tree[cnode];
    }
    int mid = (l + r) >> 1;
    node n1 = query(cnode << 1, l, mid);
    node n2 = query(cnode << 1 | 1, mid + 1, r);
    node res = merge(n1, n2);
    return res;
}

template <typename T> class SparseTable {
private:
    vector<vector<T>> table;
    std::function<T(T, T)> f;

public:
    SparseTable(vector<T> &data, std::function<T(T, T)> f) : f(f) {
        int n = data.size();
        table.pb(data);
        for (int j = 1; (1ll << j) <= n; ++j) {
            vector<T> nextRow(n);
            for (int i = 0; i + (1ll << j) <= n; ++i) {
                int otherIndex = i + (1ll << (j - 1));
                nextRow[i] = f(table.back()[i], table.back()[otherIndex]);
            }
            table.push_back(std::move(nextRow));
        }
    }
    static int msb_index(int x) { return __builtin_clz(1) - __builtin_clz(x); }

    T valueInRange(int left, int right) {
        int j = msb_index(right - left + 1);
        ll intervalSize = 1ll << j;
        return f(table[j][left], table[j][right - intervalSize + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    datt = vl(n);
    for (int i = 0; i < n; ++i) {
        cin >> datt[i];
    }
    echo(n);
    build(1, 0, n - 1);
    SparseTable<ll> sp(datt, [](ll a, ll b) { return _gcd(a, b); });

    int t;
    cin >> t;
    while (t--) {
        int r, l;
        cin >> l >> r;
        l--, r--;
        q.l = l;
        q.r = r;
        auto nde = query(1, 0, n - 1);
        echo(nde.mi);
        echo(nde.elem);

        int remain = 0;
        if (nde.mi == sp.valueInRange(l, r)) {
            remain = nde.elem;
        }

        cout << r - l + 1 - remain << "\n";
    }

    return 0;
}