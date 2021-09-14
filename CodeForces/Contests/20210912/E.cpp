//  E.cpp
//  Created by David del Val on 12/09/2021
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
vector<vi> adyList;
vi visited;
vi parent;
void findParent(int cnode) {
    visited[cnode] = true;
    for (auto a : adyList[cnode]) {
        if (!visited[a]) {
            parent[a] = cnode;
            findParent(a);
        }
    }
}
int operations = 0;
bool explore(int cnode) {
    bool allLeaves = adyList[cnode].size() != 0;
    int hasbud = 0;

    for (auto a : adyList[cnode]) {
        if (adyList[a].size() != 0) {
            allLeaves = false;
        }
        hasbud += explore(a);
    }
    if (hasbud < adyList[cnode].size()) {
        operations += hasbud;
    } else if (hasbud) {
        operations += hasbud - 1;
    }
    echo(operations);
    return hasbud > 0 || allLeaves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        visited = vi(n, 0);
        parent = vi(n, 0);
        operations = 0;
        adyList = vector<vi>(n, vi());
        int a, b;
        for (int i = 0; i < n - 1; ++i) {
            cin >> a >> b;
            a--, b--;
            adyList[a].pb(b);
            adyList[b].pb(a);
        }
        findParent(0);
        vector<vi> ady2 = vector<vi>(n, vi());
        int leaves = 0;
        for (int i = 0; i < n; ++i) {
            for (auto a : adyList[i]) {
                if (a != parent[i]) {
                    ady2[i].pb(a);
                }
            }
            if (ady2[i].size() == 0) {
                leaves++;
            }
        }
        swap(ady2, adyList);
        ll ans = 1;
        for (int i = 0; i < n; ++i) {
            ll leaves = 0;
            for (auto a : adyList[i]) {
                if (adyList[a].size() == 0) {
                    leaves++;
                }
            }
            ans = max(ans, leaves);
        }
        cout << ans << "\n";
    }

    return 0;
}