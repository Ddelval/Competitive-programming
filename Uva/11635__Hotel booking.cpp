//  11635__Hotel booking.cpp
//  Created by David del Val on 20/12/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

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

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << p.fi << " " << p.se;
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
set<int> hotels;
vector<vector<pii>> graph;
const int inf = INT_MAX / 10;

int dijkstra(int orig, int dest) {
    using piii = pair<pii, int>;
    vi dist(graph.size(), inf);
    vi mintime(graph.size(), inf);

    priority_queue<piii, vector<piii>, greater<piii>> q;

    dist[orig] = 0;
    q.push({{0, 0}, orig});

    while (!q.empty()) {
        auto a = q.top();
        q.pop();

        if (a.se == dest) {
            return a.fi.fi;
        }
        //cout << "Processing" << a.se << endl;
        if (a.fi.se < mintime[a.se]) {
            mintime[a.se] = a.fi.se;
        } else {
            continue;
        }

        // We don't stay the night
        for (auto b : graph[a.se]) {
            int ntime = a.fi.se + b.se;
            if (mintime[b.fi] > ntime && ntime <= 600) {
                q.push({{a.fi.fi, ntime}, b.fi});
            }
        }
        if (hotels.count(a.se)) {
            // We stay the night
            for (auto b : graph[a.se]) {
                int ntime = 0 + b.se;
                if (mintime[b.fi] > ntime && ntime <= 600) {
                    q.push({{a.fi.fi + 1, ntime}, b.fi});
                }
            }
        }
    }
    return inf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n && n) {
        int h;
        cin >> h;
        hotels = set<int>();
        int a;
        for (int i = 0; i < h; ++i) {
            cin >> a;
            a--;
            hotels.insert(a);
        }
        int m;
        cin >> m;
        vector<pii> ini;
        graph = decltype(graph)(n, ini);

        int b, c;
        //cout << graph.size() << endl;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            a--;
            b--;
            graph[a].pb({b, c});
            graph[b].pb({a, c});
        }
        /*         for (auto a : graph) {
            cout << a << endl;
        } */
        int cost = dijkstra(0, n - 1);
        if (cost == inf) {
            cout << "-1\n";
        } else {
            cout << cost << "\n";
        }
    }

    return 0;
}