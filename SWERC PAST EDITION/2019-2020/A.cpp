//  A.cpp
//  Created by David del Val on 16/02/2021
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

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

int B;
int N;
vector<vector<pair<int, pii>>> adyList; //destination, distance, c02

inline int dist(pii p1, pii p2) {
    return (int)ceil(sqrt(pow(p1.fi - p2.fi, 2) + pow(p1.se - p2.se, 2)));
}

ll dijkstra() {
    vi distances(N + 2, B+1);
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q; //c02,node,dist

    distances[0] = 0;
    q.push({0, {0, 0}});

    while (!q.empty()) {
        auto a = q.top();
        q.pop();

        if (a.se.fi == N + 1) {
            return a.fi;
        }
        distances[a.se.fi] = a.se.se;

        for (auto b : adyList[a.se.fi]) {
            if ((a.se.se + b.se.fi < distances[b.fi]) ) {
                q.push({a.fi + b.se.se, {b.fi, a.se.se + b.se.fi}});
            }
        }
    }
    return -1;
}

int main() {
    /*
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */

    int x_s, y_s;
    int x_d, y_d;
    int c0;
    int T;
    int a, b, c;
    vector<pii> stations;

    vector<pair<pii, int>> links;

    cin >> x_s >> y_s >> x_d >> y_d;
    cin >> B;
    cin >> c0 >> T;
    vi costs(T);
    for (int i = 0; i < T; ++i) {
        cin >> costs[i];
    }
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        stations.pb({a, b});

        cin >> c;
        for (int j = 0; j < c; ++j) {
            cin >> a >> b;
            links.pb({{i, a}, costs[b - 1]});
        }
    }
    adyList = vector<vector<pair<int, pii>>>(N + 2);
    //sort(all(links));
    for (auto a:links) {
        /*if (i && links[i].fi == links[i - 1].fi) {
            continue;
        }*/
        //auto a = links[i];

        int d = dist(stations[a.fi.fi], stations[a.fi.se]);
        adyList[a.fi.fi + 1].pb({a.fi.se + 1, {d, a.se * d}});
        adyList[a.fi.se + 1].pb({a.fi.fi + 1, {d, a.se * d}});
    }
    for (int i = 1; i <= N; ++i) {
        int d = dist({x_s, y_s}, stations[i - 1]);
        adyList[0].pb({i, {d, d * c0}});

        d = dist({x_d, y_d}, stations[i - 1]);
        adyList[i].pb({N + 1, {d, d * c0}});
    }
    int d = dist({x_s, y_s}, {x_d, y_d});
    adyList[0].pb({N + 1, {d, d * c0}});

    cout << dijkstra() << "\n";

    return 0;
}