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
int degree[51];
int main() {
    ios::sync_with_stdio(false);
    int nodes,edges,i,a,b,odd;
    while(cin>>edges&&edges){
        cin>>nodes;
        for(i=0;i<edges;++i){
            cin>>a>>b;
            degree[a]++;
            degree[b]++;
        }
        odd=0;
        for(i=1;i<=nodes;++i){
            if(degree[i]%2){
                odd++;
            }
            degree[i]=0;
        }
        if(!odd ||odd==2){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}

