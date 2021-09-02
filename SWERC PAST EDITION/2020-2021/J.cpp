//  J.cpp
//  Created by David del Val on 02/09/2021
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
const int limN = 2 * 50 + 10, limC = 20 + 10;

int n, m, c;
bool possible[limN][limN][limC];
vi successor[limN][limC];
vi predecesor[limN][limC];
bool hasPr[limN][limC];

void explore(int x, int y, int c) {
    db({ cout << x << " " << y << " " << c << endl; });
    if (possible[x][y][c]) return;
    possible[x][y][c] = true;
    for (int z = 0; z < 2 * n; ++z) {
        if (possible[z][x][c]) {
            explore(z, y, c);
        }
        if (possible[y][z][c]) {
            explore(x, z, c);
        }
    }
    for (int v : successor[y][c]) {
        for (int u : predecesor[x][c]) {
            for (int cp = 0; cp <= ::c; ++cp) {
                if (!hasPr[u][cp]) {
                    explore(u, v, cp);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> c;

    for (int i = 0; i < m; ++i) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        predecesor[a2][a3].pb(a1);
        successor[a1][a3].pb(a2);
        hasPr[a1][a3] = true;
    }

    // Cycle in the exit node
    for (int cc = 0; cc < c; ++cc) {
        echo(cc);
        successor[n - 1][cc].push_back(n - 1);
    }

    echo("hi");
    // Add the nodes before the first node
    for (int x = n; x < 2 * n; ++x) {
        for (int cc = 0; cc < c; ++cc) {
            predecesor[(x + 1) % (2 * n)][cc].push_back(x );
        }
    }

    echo("hi");
    for (int x = 0; x < 2 * n; ++x) {
        for (int cc = 0; cc <= c; ++cc) {
            explore(x, x, cc);
        }
    }

    for (int d = 2 * n; d >= 0; d--) {
        if (possible[d % (2 * n)][n - 1][c]) {
            cout << 2 * n - d << "\n";
            break;
        }
    }

    return 0;
}