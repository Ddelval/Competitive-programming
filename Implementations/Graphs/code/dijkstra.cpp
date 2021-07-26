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



int dijkstra(int orig, int dest, vector<vector<pii>> &graph) {
    vi dists(graph.size(), INT_MAX / 10);
    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, orig});
    dists[orig] = 0;
    while (!q.empty()) {
        auto a = q.top();
        q.pop();
        if (a.se == dest) { // If we already reached the destination
            return a.fi;
        }
        if (dists[a.se] != a.fi) { // If we have found a better option
            continue;
        }
        for (auto b : graph[a.se]) { // Else iterate through the edges
            if (dists[b.fi] > dists[a.se] + b.se) {
                dists[b.fi] = dists[a.se] + b.se;
                q.push({dists[b.fi], b.fi});
            }
        }
    }
    return dists[dest];
}