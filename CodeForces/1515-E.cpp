//  1515-E.cpp
//  Created by David del Val on 23/08/2021
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
const int lim = 400 + 10;
ll fact[lim];
ll inver[lim];
ll power2[lim];
ll mod;

ll powerMod(ll base, ll exp) {
    if (!exp) {
        return 1;
    }
    if (exp == 1) {
        return base;
    }
    ll a = powerMod(base, exp / 2);
    a = (a * a) % mod;
    if (exp % 2) {
        a = (a * base) % mod;
    }
    return a;
}
ll inverse(ll elem) { return powerMod(elem, mod - 2); }

ll coef(ll top, ll bot) {
    return (fact[top] * ((inver[bot] * inver[top - bot]) % mod)) % mod;
}
ll dp[lim][lim];
void ini() {
    fact[0] = fact[1] = 1;
    inver[0] = inver[1] = 1;
    power2[0] = 1;
    power2[1] = 2;
    for (int i = 2; i < lim; ++i) {
        fact[i] = (i * fact[i - 1]) % mod;
        inver[i] = inverse(fact[i]);
        power2[i] = (power2[i - 1] << 1) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n >> mod;
    ini();

    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        echo(i);
        for (int j = i / 2; j <= i; ++j) {
            echo(j);
            for (int k = 1; k < j; ++k) {
                echo(k);
                int prevTurnOn = j - k;
                if (prevTurnOn <= 0 || i - k - 1 <= 0) {
                    break;
                }
                echo(prevTurnOn);
                ll tmp = coef(prevTurnOn + k, prevTurnOn) * power2[k - 1];
                tmp %= mod;
                tmp *= dp[i - k - 1][prevTurnOn];
                tmp %= mod;
                dp[i][j] += tmp;
                dp[i][j] %= mod;
            }
        }
        dp[i][i] = power2[i - 1];
    }
    ll ans = 0;
    for (int j = 0; j <= n; ++j) {
        // cout << dp[n][j] << " ";
        ans += dp[n][j];
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}