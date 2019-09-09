//
//  main.cpp
//  FIRST
//
//  Created by David del Val on 16/06/2019.
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

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    ll x,y,z;
    while(cin>>x>>y>>z){
        ll tobuy=(x+y)/z;
        ll canbuy1=x/z;
        ll canbuy2=y/z;
        if(canbuy1+canbuy2==tobuy){
            cout<<tobuy<<" 0\n";
        }
        else{
            ll rem1=x%z;
            ll rem2=y%z;
            if(rem1>=rem2){
                cout<<tobuy<<" "<<z-rem1;
            }
            else{
                cout<<tobuy<<" "<<z-rem2;
            }
        }
    }
    
    
    
    return 0;
}
