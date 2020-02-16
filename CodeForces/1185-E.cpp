//
//  main.cpp
//  1185-E
//
//  Created by David del Val on 20/06/2019.
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
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(int j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

#define LIM 2000

int n,m;
int snakenum;
char c[LIM][LIM];
ii starts[27];
ii endss[27];
vector<vector<ii>> pos;
stack<pair<ii,ii>> results;
void inSnakes(){
    vector<ii> a;
    pos.assign(26, a);
    snakenum=-1;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>c[i][j];
            if(c[i][j]!='.'){
                pos[c[i][j]-'a'].push_back({i,j});
                snakenum=max(snakenum,c[i][j]-'a');
            }
        }
    }
}
bool inLine(){
    for(int i=snakenum;i>=0;--i){
        if(pos[i].empty())continue;
        if(pos[i].front().first==pos[i].back().first){
            //Horizontal
            for(ii in:pos[i]){
                if(in.first!=pos[i].front().first){
                    return false;
                }
            }
        }
        else if(pos[i].front().second==pos[i].back().second){
            for(ii in:pos[i]){
                if(in.second!=pos[i].front().second){
                    return false;
                }
            }
        }
        else{
            return false;
        }
    }
    return true;
}
bool finalcheck(){
    for(int i=snakenum;i>=0;--i){
        if(pos[i].empty()){
            results.push(results.top());
            continue;
        }
        if(pos[i].front().first==pos[i].back().first){
            //Horizontal
            results.push({pos[i].front(),pos[i].back()});
            for(int j=pos[i].front().second;j<=pos[i].back().second;++j){
                if(c[pos[i].front().first][j]=='.'||c[pos[i].front().first][j]<c[pos[i].front().first][pos[i].front().second]){
                    return false;
                }
            }
        }
        else if(pos[i].front().second==pos[i].back().second){
            results.push({pos[i].front(),pos[i].back()});
            for(int j=pos[i].front().first;j<=pos[i].back().first;++j){
                if(c[j][pos[i].front().second]=='.'||c[j][pos[i].front().second]<c[pos[i].front().first][pos[i].front().second]){
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    for(int z=0;z<cas;++z){
        cin>>n>>m;
        while(!results.empty())results.pop();
        inSnakes();
        if(!inLine()){
            cout<<"NO\n";
            continue;
        }
        if(!finalcheck()){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<results.size()<<"\n";
        while(!results.empty()){
            ii r=results.top().first;
            ii rr=results.top().second;
            cout<<r.first+1<<" "<<r.second+1<<" "<<rr.first+1<<" "<<rr.second+1<<"\n";
            results.pop();
        }
        
        
    }
    return 0;
}
