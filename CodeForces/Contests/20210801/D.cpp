//  D.cpp
//  Created by David del Val on 01/08/2021
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

class SparseTable {
private:
    vl logs;
    vector<vl> table;
    std::function<ll(ll, ll)> f;

public:
    SparseTable(vl &data, std::function<ll(ll, ll)> f) : f(f) {
        int n = data.size();
        table.pb(data);
        for (int j = 1; (1ll << j) <= n; ++j) {
            vl nextRow(n);
            for (int i = 0; i + (1ll << j) <= n; ++i) {
                nextRow[i] = f(table.back()[i], table.back()[i + (1ll << (j - 1))]);
            }
            table.push_back(std::move(nextRow));
        }

        logs = vl(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            logs[i] = logs[i / 2] + 1;
        }
    }

    ll valueInRange(int left, int right) {
        ll j = logs[right - left + 1];
        ll intervalSize = 1ll << j;
        return f(table[j][left], table[j][right - intervalSize + 1]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vl data = readVector<ll>(n);
        vl difs(n - 1, 0);
        for (int i = 1; i < n; ++i) {
            difs[i - 1] = abs(data[i] - data[i - 1]);
        }
        SparseTable sp(difs, [](ll a, ll b) { return _gcd(a, b); });
        n--;
        db(cout << "difs:" << difs << endl);
        ll ma = 0;
        for (int i = 0; i < n; ++i) {
            ll r = n - 1;
            if (sp.valueInRange(i, r) != 1) {
                db(cout << "direct: " << r << endl);
                ma = max(ma, r - i + 1);
            } else {
                ll l = i;
                while (r - l > 1) {
                    db(cout << "bin: " << l << " " << r << endl);
                    ll mid = (l + r) / 2;
                    if (sp.valueInRange(i, mid) == 1) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                db(cout << "bin_end: " << l << " " << r << endl);
                if (sp.valueInRange(i, l) != 1) {
                    ma = max(ma, l - i + 1);
                }
            }
        }
        cout << ma + 1 << endl;
    }

    return 0;
}