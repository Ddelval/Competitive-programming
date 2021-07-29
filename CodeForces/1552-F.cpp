//  1552-F.CPP
//  Created by David del Val on 28/07/2021
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

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
ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<pii, int>> portals;
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        portals.pb({{a, b}, c});
    }
    vector<pair<int, pii>> positions;
    for (int i = 0; i < n; ++i) {
        positions.pb({portals[i].fi.fi, {1, i}});
        positions.pb({portals[i].fi.se, {-1, i}});
    }
    sort(all(positions), greater<pair<int, pii>>());
    int bound = -1;
    vi lower_end(n, 0);
    for (int i = 0; i < positions.size(); ++i) {
        if (positions[i].se.fi == 1) {
            bound = positions[i].se.se;
        } else {
            lower_end[positions[i].se.se] = bound;
        }
    }
    // cout << lower_end << endl;
    vl presum(n + 1, 0);
    vl result(n, 0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        result[i] = (presum[i] - presum[lower_end[i]] + mod) % mod;
        result[i] += portals[i].fi.fi - portals[i].fi.se;
        result[i] %= mod;
        presum[i + 1] = (presum[i] + result[i]) % mod;

        if (portals[i].se) {
            ans += result[i];
            ans %= mod;
        }
    }
    // cout << result << endl;
    cout << (ans + portals[n - 1].fi.fi + 1) % mod << "\n";

    return 0;
}