//  C.cpp
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
double eps = 1e-9;
vector<pair<double, double>> people;
int x, y, n;
struct UFDS {
    vi parent, rankk;
    UFDS(int n) : parent(n), rankk(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return parent[node];
        }
        return parent[node] = find(parent[node]);
    }
    void unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);
        if (rankk[p1] > rankk[p2]) {
            parent[p2] = p1;
        } else if (rankk[p2] > rankk[p1]) {
            parent[p1] = p2;
        } else {
            parent[p1] = p2;
            rankk[p2]++;
        }
    }
};
bool reachable(double distancing) {
    UFDS sets(n + 2);
    for (int i = 0; i < n; ++i) {
        if (people[i].fi - distancing < eps) {
            sets.unite(i, n + 1);
        }
        if (people[i].fi + distancing > x - eps) {
            sets.unite(i, n);
        }
        if (people[i].se - distancing < eps) {
            sets.unite(i, n);
        }
        if (people[i].se + distancing > y - eps) {
            sets.unite(i, n + 1);
        }

        for (int j = 0; j < n; ++j) {
            double dx = (people[i].fi - people[j].fi);
            double dy = (people[i].se - people[j].se);
            dx *= dx;
            dy *= dy;
            double thress = 2 * distancing + eps;
            if (dx + dy <= thress * thress) {
                sets.unite(i, j);
            }
        }
    }
    echo(distancing);
    echo(sets.parent);
    return sets.find(n + 1) != sets.find(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> n;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        people.pb({a, b});
    }
    double r = max(x, y);
    double l = 0;
    if (reachable(r)) {
        l = r;
    }
    while (r - l > eps) {
        double mid = (r + l) / 2;
        if (reachable(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(7);

    cout << l << "\n";

    return 0;
}