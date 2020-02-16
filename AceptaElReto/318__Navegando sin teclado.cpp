// AceptaElReto 318:  Navegando sin teclado
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
    long N,E;
    vector<vector<pair<int,int>>> adjList;
    //Constructor
    Graph(int nn, int en){
        N=nn;
        E=en;
        vector<pair<int,int>> vi;
        adjList.assign(nn, vi);
    }
    void addEdge(int weight,int start,int end){
        adjList[start].push_back(make_pair(weight,end));
    }
    long Dijkstra();
};
long Graph::Dijkstra(){
    vector<long> distance;
    int pos,weight;
    distance.assign(N, LONG_MAX);
    distance[0]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty()){
        pos=pq.top().second;
        weight=pq.top().first;
        pq.pop();
        if(weight>distance[pos]){
            continue;
        }
        if(pos==N-1){
            break;
        }
        for(auto it=adjList[pos].begin();it!=adjList[pos].end();it++){
            if(distance[(*it).second]>distance[pos]+(*it).first){
                distance[(*it).second]=distance[pos]+(*it).first;
                pq.push(make_pair(distance[(*it).second], (*it).second));
            }
        }
    }
    
    return distance[N-1];
}
int waittime[1000];
int main() {
    ios::sync_with_stdio(false);
    int nodes,edges;
    int i,a;
    int b,c;
    long output;
    while(cin>>nodes){
        
        for(i=0;i<nodes;++i){
            cin>>a;
            waittime[i]=a;
        }
        cin>>edges;
        Graph g(nodes,edges);
        for(i=0;i<edges;++i){
            cin>>a>>b>>c;
            a--;
            b--;
            g.addEdge(c+waittime[b], a, b);
        }
        output=g.Dijkstra();
        if(output==LONG_MAX){
            cout<<"IMPOSIBLE\n";
        }
        else{
            cout<<output+waittime[0]<<"\n";
        }
    }
    return 0;
}

