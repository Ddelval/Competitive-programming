//  UVa Online Judge 00341: Non-Stop Travel.cpp
//  Created by David del Val on 21/02/2020

#include <bits/stdc++.h>
using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second


inline int _gcd(int a, int b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dist[20];
int parent[20];

pair<ll,vi> Dijkstra(vector<vector<pii>> &ady, int s, int e){

    for(int i=0;i<20;++i)dist[i]=LLONG_MAX/10;
    parent[s]=-1;
    dist[s]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    ll cos=-1;
    while(!pq.empty()){
        auto p=pq.top(); pq.pop();

        if(p.se==e){
            cos=p.fi;
            break;
        }
        for(auto a:ady[p.se]){
            if(a.se+p.fi<dist[a.fi]){
                dist[a.fi]=a.se+p.fi;
                parent[a.fi]=p.se;
                pq.push({dist[a.fi],a.fi});
            }
        }
    }
    if(cos==-1)return {-1,vi()};
    int n=e;
    vi path;
    path.push_back(n);
    while(n!=s){
        n=parent[n];
        path.push_back(n);
    }


    return {cos,path};
}




int main(){

    int n;
    int cnt=1;
    while(cin>>n&&n){
        vector<vector<pii>> adyList;
        for(int i=0;i<n;++i){
            int a,b,c;
            vector<pii> vp;
            cin>>a;
            for(int i=0;i<a;++i){
                cin>>b>>c;
                vp.push_back({b-1,c});
            }
            adyList.pb(vp);
        }
        int s,e;
        cin>>s>>e;
        s--;
        e--;
        auto t=Dijkstra(adyList,s,e);
        reverse(t.se.begin(),t.se.end());
        cout<<"Case "<<cnt<<": Path =";
        for(auto a:t.se)cout<<" "<<a+1;
        cout<<"; "<<t.fi<<" second delay\n";

        cnt++;
    }

    

    return 0;
}