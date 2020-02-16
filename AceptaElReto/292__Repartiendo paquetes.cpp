// AceptaElReto 292:  Repartiendo paquetes
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
void dijkstra(int start, vector<vector<ii>> &adj,vector<ll> &dist){
    int dis,pos;
    dist.assign(adj.size(), LONG_MAX);
    dist[start]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        dis=pq.top().first;
        pos=pq.top().second;
        pq.pop();
        if(dis>dist[pos]){
            continue;
        }
        for(auto it=adj[pos].begin(); it!=adj[pos].end();it++){
            if(dis+(*it).second<dist[(*it).first]){
                dist[(*it).first]=dis+(*it).second;
                pq.push(make_pair(dist[(*it).first],(*it).first));
            }
           
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    vector<ll> dist1;
    vector<ll> dist2;
    int nodes=0;
    int edges;
    int i;
    long effort,add;
    int a,b,c;
    bool pos;
    int starting_n, target_c, target;
    while(cin>>nodes>>edges){
        vector<vector<pair<int,int>>> adj1(nodes,vector<pair<int,int>>());
        vector<vector<pair<int,int>>> adj2(nodes,vector<pair<int,int>>());
        for(i=0;i<edges;++i){
            cin>>a>>b>>c;
            a--;
            b--;
            adj1[a].push_back(ii(b,c));
            adj2[b].push_back(ii(a,c));
        }
        cin>>starting_n>>target_c;
        starting_n--;

        
        dijkstra(starting_n, adj1, dist1);
        dijkstra(starting_n, adj2, dist2);
        effort=0;
        pos=true;
        for(i=0;i<target_c;++i){
            cin>>target;
            target--;
            if(pos){
                add=dist1[target];
                if(add==LONG_MAX){
                    pos=false;
                    cout<<"Imposible\n";
                    continue;
                }
                effort+=add;
                add=dist2[target];
                if(add==LONG_MAX){
                    pos=false;
                    cout<<"Imposible\n";
                    continue;
                }
                effort+=add;
            }
            
        }
        if(pos){
            cout<<effort<<"\n";
        }
        
    }
    return 0;
}

