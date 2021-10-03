//  12775__Gift Dilemma.cpp
//  Created by David del Val on 15/09/2021
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

pll restrictRange(pll range, ll n, ll m, pll imageRange) {
    int sign = m > 0 ? 1 : -1;
    ll low = -sign * inf, high = sign * inf;

    if (imageRange.fi != -inf) {
        low = ((imageRange.fi - n) / m);
        if (low * m + n < imageRange.fi) {
            low += sign;
        }
    }

    if (imageRange.se != inf) {
        high = ((imageRange.se - n) / m);
        if (high * m + n > imageRange.se) {
            high -= sign;
        }
    }

    // Maybe reverse the endpoints
    std::tie(low, high) = pll(min(low, high), max(low, high));

    return {max(low, range.fi), min(high, range.se)};
}

// Let the result be {g,{x,y}}. Then x*a + y*b = g
ll gcdEx(ll a, ll b, ll &x, ll &y) {
    ll x1 = 0, y1 = 1;
    x = 1;
    y = 0;

    while (b) {
        ll q = a / b;
        tie(x, x1) = pii(x1, x - q * x1);
        tie(y, y1) = pii(y1, y - q * y1);
        tie(a, b) = pii(b, a - q * b);
    }
    return a;
}
struct DioEq {
    // Equation of the form ax + by = c
    // where x,y are the unknowns
    ll a, b, c;
    ll x0, y0, g;
    pll rangeOfK = {0, -1};
    bool solvable = true;

    DioEq(){};
    DioEq(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {
        // Find a solution
        ll xg, yg;
        g = gcdEx(abs(a), abs(b), xg, yg);
        if (c % g != 0) {
            this->solvable = false;
        }
        x0 = xg * (c / g);
        y0 = yg * (c / g);
        if (a < 0) x0 = -x0;
        if (b < 0) y0 = -y0;
        // db(cout << x0 << " " << y0 << endl;);
    }

    pll findRangeOfK(pll rangeX, pll rangeY) {
        pll rangeK(-inf, inf);
        if (!this->solvable) {
            return {0, -1};
        }

        rangeK = restrictRange(rangeK, x0, b / g, rangeX);
        // echo(rangeK);
        rangeK = restrictRange(rangeK, y0, -a / g, rangeY);
        // echo(rangeK);
        return rangeK;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int z = 0;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll g = _gcd(_gcd(a, b), c);
        if (d % g) {
            cout << "Case " << ++z << ": " << 0 << "\n";
            continue;
        }
        a /= g;
        b /= g;
        c /= g;
        d /= g;

        ll ans = 0;
        while (d >= 0) {
            DioEq e1(a, b, d);
            pll rangeK = e1.findRangeOfK({0, inf}, {0, inf});
            if (rangeK.fi <= rangeK.se) ans += rangeK.se - rangeK.fi + 1;
            d -= c;
        }
        cout << "Case " << ++z << ": " << ans << "\n";
    }

    return 0;
}