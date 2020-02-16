//
//  main.cpp
//  1182-D
//
//  Created by David del Val on 11/06/2019.
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
ll mod=1e9+7;
ll po(ll a, ll b){
    ll aux=a;
    for(ll i=1;i<b;++i){
        aux*=a;
        aux%=mod;
    }
    return aux;
}
int main(){
    ios::sync_with_stdio(false);
    ll n,f1,f2,f3;
    int c;
    cin>>n>>f1>>f2>>f3>>c;
    ll f_1,f_2,f_3;
    f_1=f3;
    f_2=f2;
    f_3=f1;
    ll f_n;
    for(int i=4;i<=n;++i){
        f_n=(ll)po(c,2*i-6)%mod;
        f_n*=f_1;
        f_n%=mod;
        f_n*=f_2;
        f_n%=mod;
        f_n*=f_3;
        f_n%=mod;
        f_3=f_2;
        f_2=f_1;
        f_1=f_n;
    }
    cout<<f_n;
    return 0;
}
