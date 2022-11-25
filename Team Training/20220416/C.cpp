//  C.cpp
//  Created by David del Val on 16/04/2022
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

ll dist(pll p1, pll p2) { return abs(p1.fi - p2.fi) + abs(p1.se - p2.se); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pll p[3];

    for (int i = 0; i < 3; ++i) {
        cin >> p[i].fi >> p[i].se;
    }

    vector<vi> perms = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                        {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

    ll mi = inf;
    int min_i = -1;
    for (int i = 0; i < (int)perms.size(); ++i) {
        ll len = dist(p[perms[i][0]], p[perms[i][1]]) +
                 dist(p[perms[i][1]], p[perms[i][2]]);

        pll p1, p2, p3;
        p1 = p[perms[i][0]];
        p2 = p[perms[i][1]];
        p3 = p[perms[i][2]];

        if (p3.fi >= min(p1.fi, p2.fi) && p3.fi <= max(p1.fi, p2.fi)) {
            len -= abs(p3.fi - p2.fi);
        }
        else if (p3.se >= min(p1.se, p2.se) && p3.se <= max(p1.se, p2.se)) {
            len -= abs(p3.se - p2.se);
        }
        //cout << perms[i] << "-" << len << endl;
        if (len < mi) {
            mi = len;
            min_i = i;
        }
    }
    //cout << perms[min_i] << endl;
    vii segments;
    pll p1, p2, p3;
    p1 = p[perms[min_i][0]];
    p2 = p[perms[min_i][1]];
    p3 = p[perms[min_i][2]];

    segments.pb(p1);
    if (p3.fi >= min(p1.fi, p2.fi) && p3.fi <= max(p1.fi, p2.fi)) {
        pii next = p1;
        next.se = p2.se;
        segments.pb(next);
        segments.pb(next);
        segments.pb(p2);
        next.fi = p3.fi;
        segments.pb(next);
    } else if (p3.se >= min(p1.se, p2.se) && p3.se <= max(p1.se, p2.se)) {
        pii next = p1;
        next.fi = p2.fi;
        segments.pb(next);
        segments.pb(next);
        segments.pb(p2);
        next.se = p3.se;
        segments.pb(next);
    } else {
        pii next = p1;
        next.fi = p2.fi;
        segments.pb(next);
        segments.pb(next);
        segments.pb(p2);
        next = p2;
        segments.pb(next);
        next.fi = p3.fi;
        segments.pb(next);
        segments.pb(next);
    }
    segments.pb(p3);

    cout << segments.size() / 2 << "\n";
    for (int i = 0; i < segments.size(); i += 2) {
        cout << segments[i].fi << " " << segments[i].se << " ";
        cout << segments[i + 1].fi << " " << segments[i + 1].se << "\n";
    }

    return 0;
}