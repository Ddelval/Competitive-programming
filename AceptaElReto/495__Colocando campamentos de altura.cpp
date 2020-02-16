// AceptaElReto 495:  Colocando campamentos de altura
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
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(int j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int ncamp;
int jump;
vector<vector<pair<int,int>>> adyList;
bool visited[1005];
int weights[1005];
pair<ii,bool> camp[1005];
long Dijkstra(){
    for(int i=0;i<=ncamp;i++){
        visited[i]=false;
        weights[i]=INT_MAX;
    }
    weights[0]=0;
    visited[0]=true;
    priority_queue<ii,vector<ii>,greater<ii>> prior;
    prior.push(mp(0,0));
    ii curr;
    int node,weight;
    while(!prior.empty()){
        curr=prior.top();
        prior.pop();
        if(curr.first>weights[curr.second]){
            continue;
        }
        visited[curr.second]=true;
        for(int i=0;i<adyList[curr.second].size();i++){
            node=adyList[curr.second][i].first;
            weight=adyList[curr.second][i].second;
            if(!visited[node]&&weight+curr.first<weights[node]){
                weights[node]=weight+curr.first;
                prior.push(mp(weights[node],node));
            }
        }
    }
    return weights[ncamp];
    
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>ncamp){
        vector<pair<int,int>> vp;
        adyList.assign(ncamp+1,vp);
        for(int i=0;i<ncamp;++i){
            cin>>camp[i].first.first;
        }
        for(int i=0;i<ncamp;++i){
            cin>>camp[i].first.second;
        }
        cin>>jump;
        for(int j=0;j<ncamp;++j){
            if(camp[j].first.first>jump) break;
                adyList[0].push_back(mp(j+1,camp[j].first.second));
        }
        for(int i=0;i<ncamp-1;++i){
            for(int j=i+1;j<ncamp;++j){
                if(camp[j].first.first>camp[i].first.first+jump) break;
                adyList[i+1].push_back(mp(j+1,camp[j].first.second));
            }
        }
        //echo_tablero(ncamp+1,ncamp+1,ady);
        cout<<Dijkstra()<<"\n";
    }
    
    return 0;
}

