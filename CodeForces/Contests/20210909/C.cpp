//  C.cpp
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
const int lim = 2e5 + 10;
ll factorials[lim];
const ll mod = 998244353;

void init() {
    factorials[0] = 1;
    for (int i = 1; i < lim; ++i) {
        factorials[i] = (factorials[i - 1] * i) % mod;
    }
}
ll powerMod(ll base, ll exp) {
    if (exp == 0) {
        return 1;
    }
    ll aux = powerMod(base, exp / 2);
    aux = (aux * aux) % mod;
    if (exp % 2) {
        aux = (aux * base) % mod;
    }
    return aux;
}
ll inverse(ll num) { return powerMod(num, mod - 2); }
ll comb(ll top, ll bot) {
    ll accum = factorials[top];
    accum *= inverse((factorials[bot] * factorials[top - bot]) % mod);
    accum %= mod;
    return accum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi data = readVector<int>(n);
        int maElem = *max_element(all(data));
        int maOcur = 0, malOcur = 0;
        for (auto elem : data) {
            if (elem == maElem) {
                maOcur++;
            } else if (elem == maElem - 1) {
                malOcur++;
            }
        }
        if (maOcur > 1) {
            cout << factorials[n] << "\n";
            continue;
        }
        if (malOcur == 0) {
            cout << "0\n";
            continue;
        }
        ll accum = 0;
        int rest = n - maOcur - malOcur;
        for (int i = 0; i < n; ++i) {
            if (i < malOcur) {
                continue;
            }
            ll partial = comb(rest, n - i -1);
            partial = (partial * factorials[i]) % mod;
            partial = (partial * factorials[n - i-1]) % mod;
            echo(partial);
            accum = (accum + partial) % mod;
            echo(accum);
        }
        cout << (factorials[n] + mod - accum) % mod << "\n";
    }

    return 0;
}