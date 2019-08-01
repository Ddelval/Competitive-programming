//
//  main.cpp
//  1148-A
//
//  Created by David del Val on 01/06/2019.
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
    int a,b,c;
    ll charcount;
    while(cin>>a>>b>>c){
        charcount=0;
        if(b>a){
            charcount++;
            b--;
        }
        charcount+=2*c;
        charcount+=2*min(a,b);
        if(a>b){
            charcount++;
            a--;
        }
        cout<<charcount<<"\n";
    }
    
    return 0;
}
