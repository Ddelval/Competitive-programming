#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

void dijkstra( vector<vector<pair<ll,ll>>>& graph, vector<ll>& dist, int orig){
    vi visited(graph.size(),0);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,orig});
    dist[orig]=0;
    visited[orig]=1;
    while(!pq.empty()){
        auto a=pq.top();
        pq.pop();
        for(auto b: graph[a.se]){
            if(!visited[b.fi]){
                //cout<<dist[b.fi]<<" "<<dist[a.se]<<" "<<b.se<<endl;
                if(dist[b.fi]>dist[a.se]+b.se){
                    dist[b.fi]=dist[a.se]+b.se;
                    visited[a.se]=1;
                    pq.push({dist[b.fi],b.fi});
                }
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int s,t,p;
        cin>>s>>t>>p;
        vector<pair<ll,ll>> vl1;
        vector<vector<pair<ll,ll>>> graph1(n,vl1);
        vector<vector<pair<ll,ll>>> graph2(n,vl1);
        vector<pair<ll,pair<ll,ll>>> edges;
        for(int i=0;i<m;++i){
            int a,b,c;
            
            cin>>a>>b>>c;
            a--;
            b--;
            //if(c>p)continue;
            graph1[a].push_back({b,c});
            graph2[b].push_back({a,c});
            edges.push_back({c,{a,b}});
        }

        vector<ll> dist1(n+1,LLONG_MAX/10);
        vector<ll> dist2(n+1,LLONG_MAX/10);

        dijkstra(graph1,dist1,s-1);
        dijkstra(graph2,dist2,t-1);

        /*
        for(auto a:dist1){
            cout<<a<<" ";
        }
        cout<<"\n";
        */

        sort(edges.begin(),edges.end(),greater<pair<ll,pair<ll,ll>>>());

        ll ma=-1;
        for(auto a:edges){
            ll res= dist1[a.se.fi]+dist2[a.se.se]+a.fi;
            if(res<=p)ma=max(ma,a.fi);
        }
        cout<<ma<<"\n";

    }
    return 0;
}