//
//  main.cpp
//  399-B
//
//  Created by David del Val on 30/05/2019.
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

int main(){
    ios::sync_with_stdio(false);
    string s;
    int n;
    ll counter;
    while(cin>>n>>s){
        counter=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='B') counter+=pow(2,i);
        }
        cout<<counter<<"\n";
    }
    
    return 0;
}
