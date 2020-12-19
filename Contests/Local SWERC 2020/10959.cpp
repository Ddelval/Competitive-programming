#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

vector<vector<ll>> graph;
const ll inf = 9999999;

int main(){
    ll tt, p, d, i, u, v;
    bool fis = true;
    cin >> tt;
    while(tt--) {
        if(!fis) cout << "\n";
        fis = false;

        cin >> p >> d;
        graph.assign(p, vector<ll>());
        for(i = 0; i < d; i++) {
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        vector<bool> visited(p, false);
        vector<bool> en_queue(p, false);
        en_queue[0] = true;
        vector<ll> dist(p, inf);
        dist[0] = 0;
        queue<ll> q;
        q.push(0);
        while(!q.empty()) {
            u = q.front(); q.pop();
            if(visited[u]) continue;
            visited[u] = true;
            for(auto el : graph[u]) {
                if(en_queue[el]) continue;
                en_queue[el] = true;
                q.push(el);
                //cout << "el" << el << " " << u << " " << dist[u] << endl;
                dist[el] = dist[u] +1;
            }
        }
        for(i = 1; i < p; i++) {
            cout << dist[i] << "\n";
        }
    }


    return 0;
}