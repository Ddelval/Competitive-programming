//  D.cpp
//  Created by David del Val on 12/06/2022
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
char ask1(int pos) {
    pos++;
    cout << "? 1 " << pos << endl;
    cout.flush();
    char a;
    cin >> a;
    if (a == 0) {
        exit(-1);
    }
    return a;
}
int ask2(int initial, int end) {
    initial++;
    end++;
    cout << "? 2 " << initial << " " << end << endl;
    cout.flush();
    int a;
    cin >> a;
    if (a == 0) {
        exit(-1);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string res;
    vector<pair<int, char>> markers;
    map<char, int> lastOccur;
    markers.push_back({0, ask1(0)});
    res.pb(markers.back().se);
    lastOccur[markers.back().se] = 0;
    for (int i = 1; i < n; ++i) {
        if (ask2(0, i) > markers.size()) {
            markers.push_back({i, ask1(i)});
            lastOccur[markers.back().se] = i;
            res.pb(markers.back().se);
        } else {
            vector<pair<int, char>> points;
            for (auto a : lastOccur) {
                points.pb({a.se, a.fi});
            }
            sort(all(points));
            int l = 0;
            int nn = points.size();
            int r = points.size();
            points.pb({i, '0'});
            echo(points);
            while (r - l > 1) {
                int mid = (r + l) / 2;
                echo(mid);
                int no_rep = nn - mid + 1;
                echo(no_rep);
                if (ask2(points[mid].fi, i) != no_rep) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            l = points[l].fi;
            res.pb(res[l]);
            lastOccur[res[l]] = i;
        }
    }
    cout << "! " << res << endl;
    cout.flush();

    return 0;
}