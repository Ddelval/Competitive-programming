#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define fi first
#define se second


typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;


vector<vector<piii>> adyList;

int b;
int n;



vector<int> distan;
int dijkstra(){
    distan=vector<int>(adyList.size()+2,b+1);

    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,{0,0}});

    while(!pq.empty()){
        piii t=pq.top(); pq.pop();
        if(t.se.se==n+1)return t.fi;
        distan[t.se.se]=t.se.fi;

        for(auto p: adyList[t.se.se]){
            if(p.se.fi+t.se.fi>b)continue;
            if(p.se.fi+t.se.fi<distan[p.se.se]){
                pq.push({t.fi+p.fi,{t.se.fi+p.se.fi,p.se.se}});
            }
        }
    }
    
    return -1;
}


int main(){

    int xs,ys,xd,yd;

    cin>>xs>>ys>>xd>>yd;
    cin>>b;

    int c0;
    cin>>c0;
    int t;
    cin>>t;
    vi cos(t);
    for(int i=0;i<t;++i)cin>>cos[i];
    cin>>n;
    vector<pii> stations;
    vector<pair<int,pii>> connections;

    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        stations.pb({a,b});
        int l;
        cin>>l;
        for(int j=0;j<l;++j){
            int v,w;
            cin>>v>>w;
            connections.pb({w,{i+1,v+1}});
        }
    }
    adyList=vector<vector<piii>>(n+2,vector<piii>());
    int dist;
    for(auto a:connections){
        dist=ceil(sqrt(pow(stations[a.se.fi-1].fi-stations[a.se.se-1].fi,2)+pow(stations[a.se.fi-1].se-stations[a.se.se-1].se,2)));
        adyList[a.se.fi].pb({dist*cos[a.fi-1],{dist,a.se.se}});
        adyList[a.se.se].pb({dist*cos[a.fi-1],{dist,a.se.fi}});
    }

    for(int i=0;i<n;++i){
        dist=ceil(sqrt(pow(stations[i].fi-xs,2)+pow(stations[i].se-ys,2)));
        adyList[0].pb({dist*c0,{dist,i+1}});

        dist=ceil(sqrt(pow(stations[i].fi-xd,2)+pow(stations[i].se-yd,2)));
        adyList[i+1].pb({dist*c0,{dist,n+1}});
    }


    dist=ceil(sqrt(pow(xd-xs,2)+pow(yd-ys,2)));
    adyList[0].pb({dist*c0,{dist,n+1}});

    cout<<dijkstra()<<"\n";



    return 0;
}