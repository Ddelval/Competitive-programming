// AceptaElReto 352:  Los amigos de mis amigos son mis amigos
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
using namespace std;
int maxim;
struct Graph{
    int N,V;
    map<int,vector<int>> adyList;
    map<int,int> explored;
    Graph(int nn,int nv){
        vector<int> vi;
        N=nn;
        V=nv;
    }
    void addEdge(int start,int end){
        adyList[start].push_back(end);
        explored[start]=0;
        explored[end]=0;
        adyList[end].push_back(start);
    }
    int DFS(int startingnode);
    void Keepsearching();
};

void Graph::Keepsearching(){
    int aux;
    for(auto it=explored.begin();it!=explored.end();it++){
        if(!(*it).second){
            aux=DFS((*it).first);
            if(aux>maxim){
                maxim=aux;
            }
        }
    }
}
int Graph::DFS(int startingnode){
    queue<int> process;
    int cnode;
    int count=1;
    process.push(startingnode);
    explored[startingnode]=true;
    while(!process.empty()){
        cnode=process.front();
        process.pop();
        for(auto it=adyList[cnode].begin();it!=adyList[cnode].end();it++){
            if(!explored[*it]){
                count++;
                process.push(*it);
                explored[*it]=true;
            }
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int ver,edg;
    int a,b;
    cin>>cas;
    for(int i=0;i<cas;++i){
        cin>>ver>>edg;
        Graph g(ver,edg);
        for(int j=0;j<edg;++j){
            cin>>a>>b;
            g.addEdge(a,b);
        }
        maxim=1;
        g.Keepsearching();
        cout<<maxim<<"\n";
    }
    return 0;
}

