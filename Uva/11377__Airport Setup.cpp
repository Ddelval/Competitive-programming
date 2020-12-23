// UVa Online Judge 11377: Airport Setup
//  Created by David del Val on 19/12/2020
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
    o << "(" << p.fi << " " << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

int dijkstra(int orig, int dest, vector<vector<pii>> &graph) {
    vi dists(graph.size(), INT_MAX / 10);

    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, orig});
    dists[orig] = 0;
    while (!q.empty()) {
        auto a = q.top();
        q.pop();
        //cout << dists << endl;

        if (a.se == dest) {
            //cout << a.fi << endl;
            return a.fi;
        }
        if (dists[a.se] != a.fi) {
            continue;
        }

        for (auto b : graph[a.se]) {
            if (dists[b.fi] > dists[a.se] + b.se) {
                dists[b.fi] = dists[a.se] + b.se;
                q.push({dists[b.fi], b.fi});
            }
        }
    }

    return dists[dest];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int z = 0;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi airports = readVector<int>(k);
        set<int> hasAirport;

        for (auto &a : airports) {
            a--;
            hasAirport.insert(a);
        }

        vector<vector<pii>> graph(n + 1, vector<pii>());
        int a, b;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back({b, 1 - hasAirport.count(b)});
            graph[b].push_back({a, 1 - hasAirport.count(a)});
        }

        //for (int i = 0; i < n; ++i) {
        //   cout << graph[i] << endl;
        //}

        z++;
        cout << "Case " << z << ":\n";

        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            int cost = dijkstra(x, y, graph);
            if (x != y && hasAirport.count(x) == 0) {
                cost++;
            }
            if (cost >= INT_MAX / 10) {
                cout << "-1\n";
            } else {
                cout << cost << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}