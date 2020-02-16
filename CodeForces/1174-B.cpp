//
//  main.cpp
//  1174-B
//
//  Created by David del Val on 09/06/2019.
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
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int n;
vector<int> raw;
bool ev, un;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        ev=un=false;
        raw.clear();
        raw.reserve(n);
        int in;
        for(int i=0;i<n;++i){
            cin>>in;
            raw.push_back(in);
            if(in%2)un=true;
            else ev=true;
        }
        if(un&&ev)sort(raw.begin(),raw.end());
        cout<<raw[0];
        for(int i=1;i<n;++i){
            cout<<" "<<raw[i];
        }
        //cout<<"\n";
        
    }
    
    return 0;
}
