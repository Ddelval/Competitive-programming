//  1520-G.cpp
//  Created by David del Val on 06/08/2021
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

const int lim = 2e3;
int board[lim][lim];
int portalIDs[lim][lim];
ll portalVals[lim * lim];
ll n, m, w;
int portalCount;
bool visited[lim][lim];
int endDistance;

vi bfs(int orig_i, int orig_j) {
    vi distances(portalCount, iinf);
    queue<pair<pii, int>> q;
    visited[orig_i][orig_j] = 1;
    q.push({{orig_i, orig_j}, 0});
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int portal = portalIDs[current.fi.fi][current.fi.se];
        if (portal != -1) {
            distances[portal] = current.se;
        }

        if (current.fi == make_pair((int)n - 1, (int)m - 1)) {
            endDistance = current.se;
        }

        pii children[4] = {
            current.fi + make_pair(-1, 0), current.fi + make_pair(0, -1),
            current.fi + make_pair(1, 0), current.fi + make_pair(0, 1)};

        for (int i = 0; i < 4; ++i) {
            pii child = children[i];
            if (child.fi >= 0 && child.se >= 0 && child.fi < n &&
                child.se < m) {
                if (board[child.fi][child.se] > -1 &&
                    !visited[child.fi][child.se]) {
                    visited[child.fi][child.se] = true;
                    q.push({child, current.se + 1});
                }
            }
        }
    }
    return distances;
}

void findPortals() {
    portalCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] > 0) {
                portalIDs[i][j] = portalCount;
                portalVals[portalCount] = board[i][j];
                portalCount++;
            } else {
                portalIDs[i][j] = -1;
            }
        }
    }
}
void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << portalIDs[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> w;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    findPortals();
    db(print());
    endDistance = iinf;
    auto fromSource = bfs(0, 0);
    ll ans;
    if (endDistance != iinf) {
        ans = endDistance * w;
    } else {
        ans = inf;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = 0;
        }
    }

    auto toDest = bfs(n - 1, m - 1);

    echo(fromSource);
    echo(toDest);

    ll ans1 = inf;
    ll ans2 = inf;
    for (int i = 0; i < portalCount; ++i) {
        if (fromSource[i] != iinf) {
            ans1 = min(ans1, fromSource[i] * w + portalVals[i]);
        }
        if (toDest[i] != iinf) {
            ans2 = min(ans2, toDest[i] * w + portalVals[i]);
        }
    }
    ans = min(ans, ans1 + ans2);
    if (ans == inf) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}