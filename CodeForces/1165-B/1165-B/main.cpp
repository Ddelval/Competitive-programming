//
//  main.cpp
//  1165-B
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
    vector<int> data;
    int leng;
    int index;
    int days;
    int in;
    while(cin>>leng){
        data.reserve(leng);
        for(int i=0;i<leng;++i){
            cin>>in;
            data.push_back(in);
        }
        sort(data.begin(),data.end());
        index=0;
        days=1;
        while(index<leng){
            while(index<leng&&data[index]<days)index++;
            if(index>=leng)break;
            days++;
            index++;
        }
        days--;
        cout<<days<<"\n";
    }
    
    return 0;
}
