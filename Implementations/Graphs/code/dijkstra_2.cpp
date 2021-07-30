#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

const int iinf = INT_MAX / 10;
int B;
using pipii = pair<int, pii>;
vector<vector<pipii>> adyList; //destination, cost, distance
ll dijkstra(int orig, int dest) {
    vi distances(adyList.size(), iinf);
    priority_queue<pipii, vector<pipii>, greater<pipii>> q; //cost,node,dist

    distances[orig] = 0;
    q.push({orig, {0, 0}});

    while (!q.empty()) {
        auto a = q.top();
        q.pop();

        if (a.se.fi == dest) {
            return a.fi;
        }
        distances[a.se.fi] = a.se.se;

        for (auto b : adyList[a.se.fi]) {
            if ((a.se.se + b.se.se < distances[b.fi]) ) {
                q.push({a.fi + b.se.fi, {b.fi, a.se.se + b.se.se}});
            }
        }
    }
    return -1;
}