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

//
//
vi bellmanFord(int orig, vector<pair<pii, int>> edges, int n) {
    vi dist(n, INT_MAX / 10);
    dist[orig] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            dist[e.fi.se] = min(dist[e.fi.se], dist[e.fi.fi] + e.se);
        }
    }
    // dist[i] contains the shortest path from 0 to i

    //We can now check for a negative cycle
    bool negativeCycle = false;
    for (auto e : edges) {
        if (dist[e.fi.se] > min(dist[e.fi.se], dist[e.fi.fi] + e.se)) {
            negativeCycle = true;
        }
    }
    return dist;
}