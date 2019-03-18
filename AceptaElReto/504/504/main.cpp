#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int nnodes;
int nedges;
int visited[20005];
ll lengths[20005];
int ns[20005];
vector<vector<ii>> AdyList;
ll BFS(int b,int e){
    queue<ii> q;
    for(int i=0;i<=nnodes;++i){
        visited[i]=0;
    }
    q.push({b,0});
    ll curr,length;
    while(!q.empty()){
        curr=q.front().first;
        length=q.front().second;
        if(curr==e) return length;
        q.pop();
        visited[curr]=2; //Closed node
        for(ii el:AdyList[curr]){
            if(!visited[el.first]){
                visited[el.first]=1;
                q.push({el.first,length+1});
            }
        }
    }
    return INT_MAX;
}
pair<ll,ll> Dijkstra(int b,int e){
    priority_queue<pair<ll,ii>,vector<pair<ll,ii>>,greater<pair<ll,ii>>> q;
    for(int i=0;i<=nnodes;++i){
        visited[i]=0;
        lengths[i]=INT_MAX;
        ns[i]=0;
    }
    lengths[b]=0;
    q.push({0,{b,0}});
    ll curr;
    ll length;
    ll n;
    while(!q.empty()){
        curr=q.top().second.first;
        length=q.top().first;
        n=q.top().second.second;
        q.pop();
        if(curr==e) return{lengths[e],ns[e]};
        if(length>lengths[curr]) continue;
        visited[curr]=2; //Closed node
        for(ii el:AdyList[curr]){
            if(!visited[el.first]){
                if(length+el.second<lengths[el.first]){
                    lengths[el.first]=length+el.second;
                    ns[el.first]=ns[curr]+1;
                    q.push({lengths[el.first],{el.first,n+1}});
                }
                else if(length+el.second==lengths[el.first]){
                    if(ns[el.first]>ns[curr]+1){
                        ns[el.first]=ns[curr]+1;
                    }
                }
                
            }
        }
    }
    return{lengths[e],ns[e]};
}
int main(){
    ios::sync_with_stdio(false);
    int a,b,c,consul;
    ll bf;
    pair<ll,ll> di;
    while(cin>>nnodes>>nedges){
        AdyList.clear();
        vector<ii> v;
        AdyList.assign(nnodes+1, v);
        for(int i=0;i<nedges;++i){
            cin>>a>>b>>c;
            AdyList[a].push_back({b,c});
            AdyList[b].push_back({a,c});
        }
        cin>>consul;
        for(int i=0;i<consul;++i){
            cin>>a>>b;
            bf=BFS(a, b);
            if(bf==INT_MAX){
                cout<<"SIN CAMINO\n";
                continue;
            }
            di=Dijkstra(a, b);
            if(bf==di.second)   cout<<di.first<<" SI\n";
            else                cout<<di.first<<" NO\n";
            
        }
        cout<<"----\n";
    }
    
    return 0;
}

