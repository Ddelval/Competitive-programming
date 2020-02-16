//
//  main.cpp
//  Third
//
//  Created by David del Val on 19/06/2019.
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
    priority_queue<int> times;
    priority_queue<int,vector<int>,greater<int>> selected;
    ll n, m;
    ll psum=0;
    ll hasleft=0;
    int a;
    cin>>n>>m;
    bool nf=false;
    for(int i=0;i<n;++i){
        cin>>a;
        psum+=a;
        if(psum>m){
            while(psum>m){
                hasleft++;
                psum-=times.top();
                selected.push(times.top());
                times.pop();
            }
            if(nf)cout<<" ";
            nf=true;
            cout<<hasleft;
            
        }
        else{
            if(nf)cout<<" ";
            nf=true;
            cout<<hasleft;
            
        }
        int aux=0;
        bool b=false;
        if(!selected.empty()&&a>selected.top()){
            while(true){
            b=true;
            aux+=selected.top();
            if(aux>a){
                aux-=selected.top();
                selected.push(a);
                hasleft++;
                psum-=(a-aux);
                break;
            }
            times.push(selected.top());
            selected.pop();
            if(selected.empty()){
                selected.push(a);
                psum-=(a-aux);
                break;
            }
            hasleft--;
            }
        }
        if(!b){
            times.push(a);
        }

    }
    return 0;
}
