//
//  main.cpp
//  1176-B
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

int main(){
    ios::sync_with_stdio(false);
    int mod0,mod1,mod2;
    int t,n;
    while(cin>>t){
        for(int i=0;i<t;++i){
            cin>>n;
            int a;
            mod0=mod1=mod2=0;
            for(int i=0;i<n;++i){
                cin>>a;
                if(a%3==0) mod0++;
                if(a%3==1) mod1++;
                if(a%3==2) mod2++;
            }
            if(mod1==mod2){
                cout<<mod0+mod1<<"\n";
            }
            else if (mod1>mod2){
                cout<<mod0+mod2+(mod1-mod2)/3<<"\n";
            }
            else{
                cout<<mod0+mod1+(mod2-mod1)/3<<"\n";
            }
        }
    }
    
    return 0;
}
