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
int maxsize;
int parent[20001];
int size[20001];
struct DisjointSet{
    int n;
    DisjointSet(int nn){
        n=nn;
        for(int i=0;i<n+1;++i){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findRoot(int node){
        
        if(parent[node]!=node){
            parent[node]=findRoot(parent[node]);
        }
        return parent[node];
    }
    void Union(int x1,int x2){
        int p1,p2;
        p1=findRoot(x1);
        p2=findRoot(x2);
        //out();
        if(size[p1]>=size[p2]){
            parent[p2]=p1;
            size[p1]+=size[p2];
            if(size[p1]>maxsize){
                maxsize=size[p1];
            }
        }
        else if(size[p1]<size[p2]){
            parent[p1]=p2;
            size[p2]+=size[p1];
            if(size[p2]>maxsize){
                maxsize=size[p2];
            }
        }
        
    }
    
};
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int n,edg;
    int a,b;
    cin>>cas;
    for(int i=0;i<cas;++i){
        cin>>n>>edg;
        DisjointSet ds(n);
        maxsize=1;
        for(int j=0;j<edg;j++){
            cin>>a>>b;
            if(ds.findRoot(a)!=ds.findRoot(b)){
                ds.Union(a,b);
            }
            
        }
        cout<<maxsize<<"\n";
    }
    return 0;
}

