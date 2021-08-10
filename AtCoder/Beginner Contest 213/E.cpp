//  E.cpp
//  Created by David del Val on 09/08/2021
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
inline pii operator-(pii a, pii b) { return {a.fi - b.fi, a.se - b.se}; }

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
const int lim = 500 + 2;
char board[lim][lim];
int dist[lim][lim];
int h, w;

vii punchDeltas = {{-2, -1}, {-2, 0}, {-2, 1}, {-1, -2}, {-1, -1},
                   {-1, 0},  {-1, 1}, {-1, 2}, {2, -1},  {2, 0},
                   {2, 1},   {1, -2}, {1, -1}, {1, 0},   {1, 1},
                   {1, 2},   {0, -2}, {0, -1}, {0, 1},   {0, 2}};

int Dijkstra(pii start) {
    using piii = pair<int, pii>;

    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, start});
    dist[start.fi][start.se] = 0;
    while (!pq.empty()) {
        piii curr = pq.top();
        pq.pop();
        pii pos = curr.se;
        echo(pos);
        if (curr.fi > dist[pos.fi][pos.se]) {
            continue;
        }
        dist[pos.fi][pos.se] = curr.fi;
        if (pos.fi == h - 1 && pos.se == w - 1) {
            return curr.fi;
        }

        vector<pii> adj = {pos - pii{0, 1}, pos - pii{1, 0}, pos + pii{0, 1},
                           pos + pii{1, 0}};
        echo(adj);

        for (auto npos : adj) {
            if (npos.fi < 0 || npos.se < 0 || npos.fi >= h || npos.se >= w) {
                continue;
            }
            if (board[npos.fi][npos.se] == '#') {
                continue;
            }
            int nDist = dist[pos.fi][pos.se];
            echo(nDist);
            echo(dist[npos.fi][npos.se]);
            db(cout << endl);
            if (dist[npos.fi][npos.se] > nDist) {
                pq.push({nDist, npos});
                dist[npos.fi][npos.se] = nDist;
            }
        }
        for (pii delta : punchDeltas) {
            pii npos = delta + pos;
            if (npos.fi < 0 || npos.se < 0 || npos.fi >= h || npos.se >= w) {
                continue;
            }
            int nDist = dist[pos.fi][pos.se] + 1;
            if (dist[npos.fi][npos.se] > nDist) {
                pq.push({nDist, npos});
                dist[npos.fi][npos.se] = nDist;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            board[i][j] = c;
            dist[i][j] = iinf;
        }
    }
    cout << Dijkstra({0, 0}) << "\n";

    return 0;
}