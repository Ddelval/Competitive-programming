#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll, ll>;
using vi=vector<int>;

const int MAX = 10005;
int parent[MAX];
int _rank[MAX];

int find_parent(int num) {
    if(parent[num] == num) return num;
    return parent[num] = find_parent(parent[num]);
}
bool is_connected(int num1, int num2) {
    return find_parent(num1) == find_parent(num2);
}
void Union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(_rank[a] < _rank[b]) {
        parent[a] = b;
    } else if(_rank[a] > _rank[b]) {
        parent[b] = a;
    } else {
        _rank[a]++;
        parent[a] = b;
    }
}

int main(){
    ll tt, x, y, c, i, n, m, cost, a, zz;
    vector<vector<pll>> graph;
    cin >> tt;
    for(zz = 1; zz <= tt; zz++) {
        cost = 0;
        for(i = 0; i < MAX; i++) {
            parent[i] = i;
            _rank[i] = 1;
        }
        cin >> n >> m >> a;
        graph.assign(n+1, vector<pll>());
        vector<pair<ll, pair<ll, ll>>> edge;
        for(i = 0; i < m; i++) {
            cin >> x >> y >> c;
            if(c < a) {
                graph[x].pb(mp(y, c));
                graph[y].pb(mp(x, c));
                edge.pb(mp(c, mp(x, y)));
            }
        }
        sort(edge.begin(), edge.end());
        for(auto e : edge) {
            x = e.se.fi;
            y = e.se.se;
            if(!is_connected(x, y)) {
                cost += e.fi;
                Union(x, y);
            }
        }
        //cout << "cost" << cost << endl;
        ll num_c = 0;
        for(i = 1; i <= n; i++) {
            if(find_parent(i) == i) {
                num_c++;
            }
        }
        cout << "Case #" << zz << ": " << cost + a*num_c << " " << num_c << "\n";
    }


    return 0;
}