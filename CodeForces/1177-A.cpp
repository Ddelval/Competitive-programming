//
//  main.cpp
//  1177-A
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

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    /*string s;
    for(int i=1;i<10000;++i){
        s+=to_string(i);
    }
    for(int i=0;i<s.size();++i){
        cout<<i+1<<" "<<s[i]<<"\n";
    }*/
    ll k;
    cin>>k;
    ll div;
    ll pdiv;
    ll num;
    div=0;
    for(int i=1;i<100;++i){
        //Let i be the number of digits
        pdiv=div;
        div+=9*i*pow(10, i-1);
        if(k<=div){
            int digits=i;
            ll div,rem;
            num=k-pdiv;
            num--;
            div=num/digits;
            rem=num%digits;
            num=pow(10,digits-1)+div;
            string s=to_string(num);
            cout<<s[rem];
            break;
        }
    }
    return 0;
}
