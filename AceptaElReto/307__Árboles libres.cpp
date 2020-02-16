// AceptaElReto 307:  Árboles libres
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
struct Graph{
    int n,e;
    vector<vector<int>> adylist;
    
    //Constructor
    Graph(int nn,int ne){
        n=nn;
        e=ne;
        vector<int> ve;
        adylist.assign(n, ve);
    }
    void addedge(int a,int b){
        adylist[a].push_back(b);
        adylist[b].push_back(a);
    }
    bool BFS();
};
bool Graph::BFS(){
    vector<int> visited;
    queue<int> queu;
    int current;
    bool stay=true;
    bool success;
    visited.assign(n, 0);
    queu.push(0);
    while(!queu.empty()&&stay){
        current=queu.front();
        queu.pop();
        visited[current]=2;
        for(auto it=adylist[current].begin();it!=adylist[current].end();it++){
            if(!visited[*it]){
                queu.push(*it);
                visited[*it]=1;
            }
            else if(visited[*it]==1){
                stay=false;
                break;
            }
        }
    }
    if(!stay){
        return false;
    }
    success=true;
    for(auto it=visited.begin();it!=visited.end();it++){
        if(*it!=2){
            success=false;
            break;
        }
    }
    
    return success;
}
int main() {
    ios::sync_with_stdio(false);
    int nodes,edges;
    int a,b;
    while(cin>>nodes>>edges){
        Graph g(nodes,edges);
        if(edges){
            for(int i=0;i<edges;++i){
                cin>>a>>b;
                g.addedge(a, b);
            }
            if(g.BFS()){
                cout<<"SI\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            if(nodes==1){
                cout<<"SI\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        
    }
    return 0;
}

