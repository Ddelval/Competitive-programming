// UVa Online Judge 10801: Lift Hopping
//  108001
//  Created by David del Val on 16/12/2020
//
//

#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
using pii = pair<int, int>;
using vi = vector<int>;

vector<vector<pii>> edges;

int dijkstra(int orig, int dest) {
    vi visited = vi(200, 0);
    vi dist = vi(200, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, orig});
    while (!pq.empty()) {
        pii d = pq.top();
        pq.pop();
        visited[d.se] = 1;
        if (d.se == dest) {
            break;
        }
        for (auto a : edges[d.se]) {
            if (!visited[a.fi]) {
                if (dist[a.fi] > d.fi + a.se) {
                    dist[a.fi] = d.fi + a.se;
                    pq.push({d.fi + a.se, a.fi});
                }
            }
        }
    }
    /* for (int i = 0; i < 200; ++i) {
        if (dist[i] != INT_MAX)
            cout << i << " " << dist[i] << "\n";
    }*/
    return dist[dest];
}
void printgraph() {
    for (int i = 0; i < 200; ++i) {
        bool first = true;
        for (int j = 0; j < edges[i].size(); ++j) {
            if (abs(edges[i][j].fi - i) != 100) {
                if (first)
                    cout << "\n"
                         << i << " ";
                cout << "(" << edges[i][j].fi << "," << edges[i][j].se << ")";
            }
        }
    }
}
int main() {
    int n, k;
    string s;
    while (getline(cin, s)) {
        stringstream str = stringstream(s);
        str >> n >> k;
        getline(cin, s);
        str = stringstream(s);
        vi costs;
        int a;
        while (str >> a) {
            costs.push_back(a);
        }
        vector<vector<int>> elev;
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            vi data;

            str = stringstream(s);
            int a;
            while (str >> a) {
                data.push_back(a);
            }
            /*cout << "elev";
            for (auto a : data)
                cout
                    << a << " ";
            cout << "\n";*/

            elev.push_back(data);
        }
        if (k == 0) {
            cout << "0\n";
            continue;
        }
        edges = vector<vector<pii>>(200, vector<pii>());
        for (int i = 0; i < 100; ++i) {
            edges[i].push_back({100 + i, 60});
            edges[100 + i].push_back({i, 60});
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < elev[i].size(); ++j) {
                for (int w = j + 1; w < elev[i].size(); ++w) {

                    edges[elev[i][w]].push_back({100 + elev[i][j], costs[i] * (abs(elev[i][j] - elev[i][w]))});
                    edges[elev[i][j]].push_back({100 + elev[i][w], costs[i] * (abs(elev[i][j] - elev[i][w]))});
                }
            }
        }
        //printgraph();
        int r1 = dijkstra(0, k);
        int r2 = dijkstra(0, 100 + k);
        int res = min(r1, r2);
        if (res == INT_MAX) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << res << "\n";
        }
    }
}