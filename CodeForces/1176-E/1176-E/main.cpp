//
//  main.cpp
//  1176-E
//
//  Created by David del Val on 17/06/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

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
#include <string.h>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

#define IT(x,y) for(int x=0;(x)<(y); x++)
#define LIM 200000
using namespace std;
typedef pair<int,int> ii;

typedef long long ll;
vector<vector<int>> AdyList;
vector<int> even;
vector<int> odd;
bool visited[LIM];
void BFS(){
    bool parity=false;
    int b;
    queue<pair<int,bool>> q;
    q.push({0,false});
    visited[0]=true;
    even.push_back(0);
    while(!q.empty()){
        b=q.front().first;
        parity=q.front().second;
        q.pop();
        
        for(int a:AdyList[b]){
            if(!visited[a]){
                q.push({a,!parity});
                visited[a]=true;
                if(parity){
                    even.push_back(a);
                }
                else{
                    odd.push_back(a);
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    int cases;
    cin>>cases;
    IT(z,cases){
        int n,m;
        int a,b;
        cin>>n>>m;
        AdyList.clear();
        even.clear();
        odd.clear();
        AdyList.assign(n, even);
        for(int i=0;i<n;++i){visited[i]=false;}
        IT(i,m){
            cin>>a>>b;
            a--;
            b--;
            AdyList[a].push_back(b);
            AdyList[b].push_back(a);
        }
        BFS();
        vector<int> *avec;
        if(even.size()>odd.size()&&odd.size()){
            avec=&odd;
        }
        else{
            avec=&even;
        }
        cout<<(*avec).size()<<"\n";
        cout<<((*avec)[0])+1;
        for(int i=1;i<(*avec).size();++i){
            cout<<" "<<((*avec)[i])+1;
        }
        cout<<"\n";
    }
    return 0;
}
