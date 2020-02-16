//
//  main.cpp
//  1180-C
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
string out[300000];
int main() {
    ios::sync_with_stdio(false);
    deque<int> d;
    vector<pair<ll,int>> querr;
    int n,m,a;
    ll l;
    int ma=-1;;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a;
        ma=max(ma,a);
        d.push_back(a);
    }
    for(int i=0;i<m;++i){
        cin>>l;
        querr.push_back({l,i});
    }
    if(!m)return 0;
    int b;
    sort(querr.begin(),querr.end());
    auto it=querr.begin();
    int i=1;
    while(d.front()!=ma){
        a=d.front();
        d.pop_front();
        b=d.front();
        d.pop_front();
        if(a>b){
            d.push_front(a);
            d.push_back(b);
        }
        else{
            d.push_front(b);
            d.push_back(a);
        }
        while(it->first==i){
            out[it->second]=to_string(a)+" "+to_string(b);
            it++;
        }
        i++;
    }
    while(it!=querr.end()){
        out[it->second]=to_string(ma)+" "+to_string(d[(it->first-i)%(n-1)+1]);
        it++;
    }
    for(int i=0;i<m;++i){
        cout<<out[i]<<"\n";
    }
    return 0;
}
