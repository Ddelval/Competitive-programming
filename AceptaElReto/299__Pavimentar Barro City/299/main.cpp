#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;
int parent[10001];
int ranks[10001];
pair<int,pair<int,int>> pai(int w, int u, int v){
    return make_pair(w,make_pair(u,v));
}
struct Graph{
    int V,E;
    vector<pair<int,pair<int,int>>> edges;
    //Constructor
    Graph(int nv, int ne){
        V=nv;
        E=ne;
    }
    //Functions
    void addEdge(int u,int v,int w){
        edges.push_back(pai(w,u,v));
    }
    long kruskalMST();
    
};
struct DisjointSets{
    int n;
    //Constructor
    DisjointSets(int nn){
        n=nn;
        for(int i=0;i<=n;++i){
            ranks[i]=0;
            parent[i]=i;
        }
    }
    //findFunction with compression
    int findRoot(int u){
        if(u!=parent[u]){
            parent[u]=findRoot(parent[u]);
        }
        return parent[u];
    }
    //Union by ranks
    void Union(int x,int y){
        x=findRoot(x);
        y=findRoot(y);
        if(ranks[x]<ranks[y]){
            parent[x]=y;
        }
        else if(ranks[x]>ranks[y]){
            parent[y]=x;
        }
        else{
            //If ranksss are the same, make one root and increment its ranks;
            ranks[x]++;
            parent[y]=x;
        }
    }
};
long Graph::kruskalMST(){
    int output=0;
    int u,v;
    int addededges=0;
    sort(edges.begin(),edges.end());
    DisjointSets ds(V);
    for(auto it =edges.begin();it!=edges.end();it++){
        u=it->second.first;
        v=it->second.second;
        
        int set_u=ds.findRoot(u);
        int set_v=ds.findRoot(v);
        if(set_u!=set_v){
            addededges++;
            output+=it->first;
            ds.Union(set_u, set_v);
        }
        
        if(addededges==V-1){
            break;
        }
        
    }
    if(addededges!=V-1){
        return LONG_MAX;
    }
    return output;

}
typedef pair<int,pair<int,int>> iii;
typedef long long ll;
typedef vector<set<int>> vvi;
int main() {
    ios::sync_with_stdio(false);
    int a,b,c;
    int nodes,edges;
    ll weight;
    while(cin>>nodes>>edges){
        weight=0;
        if(edges){
            Graph g(nodes,edges);
            for(int i=0;i<edges;++i){
                cin>>a>>b>>c;
                a--;b--;
                g.addEdge(a,b,c);
            }
            weight=g.kruskalMST();
                
            
            if(weight==LONG_MAX){
                cout<<"Imposible\n";
            }
            else{
                cout<<weight<<"\n";
            }
            
        }
        else{
            if(nodes==1){
                cout<<"0\n";
            }
            else{
                cout<<"Imposible\n";
            }
        }
        
        
        //Consider the case with 1 node and 0 edges.
    }
    return 0;
}

