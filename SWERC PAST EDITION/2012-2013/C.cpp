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

const int mc = 15;
constexpr int lim = (1ll << mc);

ll possibilities[lim];
ll factor[lim];
ll base[lim];

ll precalc[mc];
ll maxexp[mc];

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

        ll n = 1;
        for (int i = 0; i < c; ++i) {
            ll curr = 1;
            ll accum = 1;
            for (int j = 1; j < data[i].se; ++j) {
                curr = (curr * data[i].fi) % mod;
                accum = (accum + curr) % mod;
            }
            precalc[i] = accum;
            maxexp[i] = (curr * data[i].fi) % mod;
            n = (n * maxexp[i]) % mod;
        }

        ll lim = (1ll << c);
        ll res = 0;

        possibilities[0] = 1;
        base[0] = 1;
        factor[0] = 1;

        int msb = 0;
        int hsnb = 0;
        int j;
        for (ll mask = 1; mask < lim; ++mask) {
            if (mask & (1ll << hsnb)) {
                hsnb++;
            }
            j = hsnb - 1;
            possibilities[mask] = (possibilities[mask - (1ll << j)] * (data[j].se + 1)) % mod;
            base[mask] = (base[mask - (1ll << j)] * (maxexp[j])) % mod;
            factor[mask] = (factor[mask - (1ll << j)] * (precalc[j])) % mod;
        }

        for (int i = 0; i < lim; ++i) {
            cout << possibilities[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < lim; ++i) {
            cout << base[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < lim; ++i) {
            cout << factor[i] << " ";
        }
        cout << endl;

        for (ll mask = 0; mask < lim; ++mask) {
            res += (((possibilities[mask] * base[mask]) % mod) * factor[(~mask) & ((1 << c) - 1)]) % mod;
            cout << res << endl;
        }

        cout << "Case " << z << ": " << (res + n) % mod << "\n";
    }

    return 0;
}