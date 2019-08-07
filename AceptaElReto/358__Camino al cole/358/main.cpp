// AceptaElReto 358:  Camino al cole
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
struct Graph{
    int N,E;
    int paths=0;
    vector<vector<ii>> adyList;
    vector<pair<long,int>> distances;
    Graph(int n,int e){
        N=n;
        E=e;
        vector<ii> vi;
        adyList.assign(N,vi);
    }
    void addEdge(int w, int a, int b){
        adyList[a].push_back(make_pair(w,b));
        adyList[b].push_back(make_pair(w,a));
    }
    void Dijkstra();
   // int diffPaths();
    //void findPaths(int n);
};
void Graph::Dijkstra(){
    vector<bool> closed;
    int cnode;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    distances.assign(N,make_pair(LONG_MAX,0));
    closed.assign(N,false);
    distances[0]=make_pair(0,1);
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        cnode=pq.top().second;
        pq.pop();
        if(closed[cnode]){
            continue;
        }
        closed[cnode]=true;
        if(cnode==4){
            cout<<"";
        }
        if(cnode==N-1){
            break;
        }
        for(auto it= adyList[cnode].begin();it!=adyList[cnode].end();it++){
            if(!closed[(*it).second]){
                if((*it).first+distances[cnode].first<distances[(*it).second].first){
                    distances[(*it).second].first=(*it).first+distances[cnode].first;
                    distances[(*it).second].second=distances[cnode].second;
                    pq.push(make_pair(distances[(*it).second].first,(*it).second));
                }
                else if((*it).first+distances[cnode].first==distances[(*it).second].first){
                   distances[(*it).second].second+=distances[cnode].second;
                }
            }
            
        }
    }
    
}
/*
int Graph::diffPaths(){
    if(connectedto[N-1][0]==-1){
        return 0;
    }
    else{
        findPaths(N-1);
    }
    
    
    return 0;
}
void Graph::findPaths(int n){
    if(connectedto[n][0]==-1){
        paths++;
        return;
    }
    else{
        for(int i=0;i<connectedto[n].size();i++){
            findPaths(connectedto[n][i]);
        }
    }
*/
int main() {
    ios::sync_with_stdio(false);
    int nodes,edges;
    int a,b,c;
    while(cin>>nodes>>edges){
        Graph g(nodes,edges);
        for(int i=0;i<edges;++i){
            cin>>a>>b>>c;
            a--;
            b--;
            g.addEdge(c,a,b);
        }
        g.Dijkstra();
       // g.diffPaths();
        
        cout<<g.distances[nodes-1].second<<"\n";
    }
    return 0;
}

