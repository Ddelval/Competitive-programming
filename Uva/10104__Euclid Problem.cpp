//  10104__Euclid Problem.cpp
//  Created by David del Val on 14/09/2021
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
    ll a1 = a, b1 = b;
    x = 1;
    y = 0;

    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = pii(x1, x - q * x1);
        tie(y, y1) = pii(y1, y - q * y1);
        tie(a1, b1) = pii(b1, a1 - q * b1);
    }
    return a1;
}
class DioEq {
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
        a /= g;
        b /= g;
        x0 = xg * (c / g);
        y0 = yg * (c / g);
        if (a < 0) x0 = -x0;
        if (b < 0) y0 = -y0;
    }

    pll findRangeOfK(pll rangeX, pll rangeY) {
        pll rangeK(-inf, inf);

        rangeK = restrictRange(rangeK, x0, b, rangeX);
        echo(rangeK);
        rangeK = restrictRange(rangeK, y0, -a, rangeY);
        echo(rangeK);
        return rangeK;
    }
};

bool findOneSolution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    ll xg, yg;
    g = gcdEx(abs(a), abs(b), xg, yg);
    if (c % g != 0) {
        return false;
    }
    x0 = xg * (c / g);
    y0 = yg * (c / g);
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

pll findAllSolutions(ll a, ll b, ll c, pll rangeX, pll rangeY) {
    ll x0, y0, g;
    if (!findOneSolution(a, b, c, x0, y0, g)) {
        return {0, -1};
    }
    a /= g;
    b /= g;

    pll rangeK(-inf, inf);

    rangeK = restrictRange(rangeK, x0, b, rangeX);
    echo(rangeK);
    rangeK = restrictRange(rangeK, y0, -a, rangeY);
    echo(rangeK);
    return rangeK;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    while (cin >> a >> b) {
        ll c;
        c = _gcd(a, b);
        ll x0, y0, g;
        findOneSolution(a, b, c, x0, y0, g);
        // cout << x0 << " " << y0 << " " << g << endl;
        db(cout << x0 << " " << y0 << endl;);
        ll targetK1 = (-x0 - (b / g) + 1) / (b / g);
        ll targetK2 = (-x0) / (b / g);
        ll x1, x2, y1, y2;

        x1 = x0 + targetK1 * (b / g);
        y1 = y0 + targetK1 * (a / g);

        x2 = x0 + targetK2 * (b / g);
        y2 = y0 + targetK2 * (a / g);

        ll x, y;
        if (abs(x1) + abs(y1) <= abs(x2) + abs(y2)) {
            x = x1;
            y = y1;
        } else {
            x = x2;
            y = y2;
        }
        cout << x << " " << y << " " << g << "\n";
    }

    return 0;
}