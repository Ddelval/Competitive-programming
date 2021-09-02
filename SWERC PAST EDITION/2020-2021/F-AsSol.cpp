//  F-AsSol.cpp
//  Created by David del Val on 29/08/2021
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
ll r, n, m;

const int lim = 2021 + 10;
ll bincoef[lim][lim];
void precalc() {
    bincoef[0][0] = 1;
    for (int top = 1; top < lim; ++top) {
        bincoef[top][0] = 1;
        for (int bot = 1; bot <= top; ++bot) {
            bincoef[top][bot] =
                bincoef[top - 1][bot - 1] + bincoef[top - 1][bot];
            bincoef[top][bot] %= m;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> n >> m;
    precalc();

    vl tn(n + 1, 0);
    tn[0] = 1;
    tn[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int toDivide = (i - 1) / 2;
        if ((i - 1) % 2 == 0) {
            ll a = tn[toDivide] * tn[i - 1 - toDivide];
            ll b = (a % m) * bincoef[i - 2][toDivide];
            tn[i] = (tn[i] + b % m) % m;
            toDivide--;
        }
        for (int l = 0; l <= toDivide; ++l) {
            ll a = tn[l] * tn[i - 1 - l];
            ll b = (a % m) * bincoef[i - 1][l];
            tn[i] = (tn[i] + b % m) % m;
        }
        tn[i] %= m;
    }
    vl sn(n + 1, 0);
    sn[n-r] = tn[n-r];
    for (int i = n-r; i <= n; ++i) {
        ll d = 0;
        ll ad = i - (n - r);
        echo(ad);
        for (int k = 1; k < ad; ++k) {
            ll a = (sn[i - k] * tn[k+1]) % m;
            ll b = (bincoef[ad - 1][k] * a) % m;
            d = (d + b) % m;
            echo(d);
        }
        sn[i] = (tn[i] - d + m) % m;
    }
    echo(tn);
    echo(sn);
    cout << sn[n] << "\n";

    return 0;
}