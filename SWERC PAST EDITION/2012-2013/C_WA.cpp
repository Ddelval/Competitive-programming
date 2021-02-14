//  C.cpp
//  Created by David del Val on 14/02/2021
//
//

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

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <>
struct Has_iterator<string> : subs_fail {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

ll mod = 1000000007ll;

inline bool isSet(ll mask, int bit) {
    return (mask & (1ll << bit)) != 0;
}

// ONLY USE WHEN MOD IS PRIME, ELSE USE GCD.
ll elevate(ll a, ll b) { // b >= 0.
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

// a^(mod - 1) = 1, Euler.
ll inv(ll a) {
    return elevate(((a % mod) + mod) % mod, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    int z = 0;
    cin >> t;
    while (t--) {
        z++;
        int c;
        cin >> c;
        vector<pll> data;
        int a, b;
        for (int i = 0; i < c; ++i) {
            cin >> a >> b;
            data.pb({a, b});
        }
        vl precalc(c);
        vl precalc2(c);
        vl maxexp(c);
        for (int i = 0; i < c; ++i) {
            ll curr = 1;
            ll accum = 1;
            ll accum2 = 1;
            curr = elevate(data[i].fi, data[i].se);
            accum = (elevate(data[i].fi, data[i].se + 1) - 1) * inv(data[i].fi - 1);
            accum %= mod;

            precalc[i] = accum;
            if (accum != (1 + curr) % mod) {
                precalc2[i] = (accum - curr - 1 + 2 * mod) % mod;

            } else {
                precalc2[i] = (accum + mod) % mod;
            }
            maxexp[i] = curr;
        }
        //cout << precalc << endl;
        //cout << maxexp << endl;
        ll mask = 0;
        ll lim = (1ll << c);
        ll res = 0;
        for (mask = 0; mask < lim; ++mask) {
            //cout << "mask " << mask << endl;
            ll posibilities = 1;
            ll posibilities2 = 1;
            ll factor = 1;
            int set = 0;
            ll factor2 = 1;
            ll base = 1;
            for (int j = 0; j < c; ++j) {
                if (isSet(mask, j)) {
                    posibilities = (posibilities * (data[j].se + 1)) % mod;
                    factor = (factor * precalc[j]) % mod;
                    factor2 = (factor2 * precalc2[j]) % mod;
                    base = (base * maxexp[j]) % mod;
                    set++;
                } else {
                    factor = (factor * maxexp[j]) % mod;
                    factor2 = (factor2 * maxexp[j]) % mod;
                }
            }
            if (!b) {
                posibilities2 = 0;
            }
            posibilities2 = posibilities - (1ll << set);
            if (!posibilities2) {
                factor2 = 0;
            }
            //cout << posibilities << " " << base << " " << factor << " " << factor2 << " " << posibilities2 << " " << (posibilities + posibilities2) * base + factor + factor2 << endl;
            posibilities += posibilities2;
            res += ((posibilities % mod * base) % mod);
            res += (factor + factor2) % mod;
            res %= mod;
        }
        ll finfact = 1;
        for (auto a : maxexp) {
            finfact = (finfact * a) % mod;
        }

        res += (2 * finfact) % mod;
        //cout << res;
        res = (res * 500000004ll) % mod;

        cout
            << "Case " << z << ": " << res << "\n";
    }

    return 0;
}