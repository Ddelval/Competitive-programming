// AceptaElReto 319:  La máquina calculadora
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
typedef pair<int,int> ii;
 bool used[10000];
int BFS(int n,int target){
    queue<ii> q;
    for(int i=0;i<10000;i++){
        used[i]=0;
    }
    ii a;
    a.first%=10000;
    int b;
    q.push(make_pair(n,0));
    while(!q.empty()){
        a=q.front();
        q.pop();
        a.first%=10000;
        b=(a.first+1)%10000;
        if(b==target){
            return a.second;
        }
        if(!used[b]){
            q.push(make_pair(b,a.second+1));
            used[b]=true;
        }
        if(a.first){
            b=(a.first*2)%10000;
            if(b==target){
                return a.second;
            }
            if(!used[b]){
                q.push(make_pair(b,a.second+1));
                 used[b]=true;
            }
            b=(a.first/3)%10000;
            if(b==target){
                return a.second;
            }
            if(!used[b]){
                q.push(make_pair(b,a.second+1));
                 used[b]=true;
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    int a,b;
    while(cin>>a>>b){
        if(a==b){
            cout<<"0\n";
            continue;
        }
        cout<<BFS(a,b)+1<<"\n";
    }
    return 0;
}

