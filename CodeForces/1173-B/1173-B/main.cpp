//
//  main.cpp
//  1173-B
//
//  Created by David del Val on 07/06/2019.
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
    int n;
    while(cin>>n){
        int counter=0;
        int w=ceil(((double)(n+1))/2);
        cout<<w<<"\n";
        for(int i=0;i<w;++i){
            cout<<"1 "<<i+1<<"\n";
            counter++;
            if(counter==n) break;
        }
        for(int i=1;i<w;++i){
            if(counter==n) break;
            cout<<i+1<<" "<<w<<"\n";
            counter++;
           
        }
    }
    
    return 0;
}
