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

// Let the result be {g,{x,y}}. Then x*a + y*b = g
pair<ll, pll> gcdEx(ll a, ll b) {
    ll x = 1, y = 0;
    ll x1 = 0, y1 = 1;
    ll a1 = a, b1 = b;

    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = pii(x1, x - q * x1);
        tie(y, y1) = pii(y1, y - q * y1);
        tie(a1, b1) = pii(b1, a1 - q * b1);
    }
    return {a1, {x, y}};
}
bool findOneSolution(ll a, ll b, ll c, ll *x0, ll *y0, ll *g) {
    auto res = gcdEx(abs(a), abs(b));
    *g = res.fi;
    if (c % *g != 0) {
        return false;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    while (cin >> a >> b) {
        ll g, x, y;
        auto res = gcdEx(a, b);
        g = res.fi;
        x = res.se.fi;
        y = res.se.se;
    }

    return 0;
}