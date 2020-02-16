//
//  main.cpp
//  1169-B
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
vector<ii> data;
bool checkvalid(int a, int b){
    for(int i=0;i<data.size();++i){
        if(data[i].first!=a &&data[i].first!=b && data[i].second!=a &&data[i].second!=b) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    int a,b;
    int a1,b1;
    int a2,b2;
    bool flag;
    bool onego;
    while(cin>>m>>n){
        data.reserve(n);
        flag=onego=false;
        a2=b2=INT_MAX;
        a1=b1=INT_MAX;
        data.clear();
        for(int i=0;i<n;++i){
            cin>>a>>b;
            data.push_back({a,b});
            if(!onego){
            if(flag){
                if(a1!=a && b1!=b && a1!= b && b1!=a){
                    a2=a;
                    b2=b;
                    onego=true;
                }
            }
            else{
                a1=a;
                b1=b;
                flag=true;
            }
            }
            
        }
        if(a2==INT_MAX){
            cout<<"YES";
            continue;
        }
        if(checkvalid(a1, a2)) cout<<"YES";
        else if (checkvalid(b1, a2)) cout<<"YES";
        else if (checkvalid(a1, b2)) cout<<"YES";
        else if (checkvalid(b1, b2)) cout<<"YES";
        else cout<<"NO";
    }
    
    return 0;
}
