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
//

vi topoSort;
vi visited;
vector<vi> adyList;
void dfs(int node) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    for (auto a : adyList[node]) {
        dfs(a);
    }
    topoSort.push_back(node);
}
void topologicalSort() {
    int n = adyList.size();

    visited = vi(n, 0);
    topoSort.clear();

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(all(topoSort));
}