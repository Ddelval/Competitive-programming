//
//  main.cpp
//  1185-F
//
//  Created by David del Val on 24/06/2019.
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

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned int ui;
int friends[1<<9];
vector<ui> dic[1<<9];
vector<int> prizes;
int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    ui res;
    ui aux;
    int lim,priz;
    for(int i=0;i<n;++i){
        cin>>lim;
        res=0;
        for(int j=0;j<lim;++j){
            cin>>aux;
            res|=(1<<(aux-1));
        }
        friends[res]++;
    }
    prizes.reserve(m);
    for(int i=0;i<m;++i){
        cin>>priz;
        cin>>lim;
        res=0;
        for(int j=0;j<lim;++j){
            cin>>aux;
            res|=(1<<(aux-1));
        }
        dic[res].push_back(i);
        prizes.push_back(priz);
    }
    
    for(int i=0;i<(1<<9);++i){
        sort(dic[i].begin(),dic[i].end(),[&](int i,int j){
            return prizes[i]<prizes[j];
        });
    }
    vector<int> out={-1,0,0};
    int a1,a2;
    for(int i=0;i<(1<<9);++i){
        for(int j=i;j<(1<<9);++j){
            if(dic[i].empty()||dic[j].empty())continue;
            if(i==j&&dic[i].size()<2)continue;
            a1=dic[i][0];
            a2=dic[j][0+(i==j)];
            int ans=0;
            for(int k=0;k<(1<<9);++k){
                if((k&(i|j))==k){
                    ans+=friends[k];
                }
            }
            if(ans>out[0]||(ans==out[0]&&(prizes[a1]+prizes[a2]<prizes[out[1]]+prizes[out[2]]))){
                out={ans,a1,a2};
            }
        }
    }
    cout<<out[1]+1<<" "<<out[2]+1<<"\n";
    
    return 0;
}
