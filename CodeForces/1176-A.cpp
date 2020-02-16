//
//  main.cpp
//  1176-A
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
ll next(ll a){
    if(!(a%2))return a/2;
    if(!(a%3)) return 2*a/3;
    if(!(a%5)) return 4*a/5;
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    int q;
    while(cin>>q){
        for(int i=0;i<q;++i){
            ll n;
            ll counter=0;
            cin>>n;
            while(n!=1){
                if(!(n%5)){
                    n/=5;
                    counter+=3;
                }
                else if(!(n%3)){
                    n/=3;
                    counter+=2;
                }
                else if(!(n%2)){
                    n/=2;
                    counter++;
                }
                else{
                    n=-1;
                    break;
                }
            }
            if(n==-1) cout<<n<<"\n";
            else cout<<counter<<"\n";
        }
    }
    
    return 0;
}
