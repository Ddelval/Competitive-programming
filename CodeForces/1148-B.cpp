//
//  main.cpp
//  1148-B
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
int numAtoB, numBtoC;
int ftA,ftB;
vector<int> fA,fB;
int k;
vector<int>::iterator lw;
int checktime(int pos ){
    int tocancell;
    if(pos>k) return 0;
    tocancell=k-pos;
    auto it= lower_bound(lw, fB.end(), fA[pos]);
    lw=it;
    if(fB.end()-it<=tocancell) return -1;
    return *(it+tocancell);
}

int main(){
    ios::sync_with_stdio(false);
    int ma;
    int aux;
    while(cin>>numAtoB>>numBtoC>>ftA>>ftB>>k){
        fA.clear();
        fA.reserve(numAtoB);
        for(int i=0;i<numAtoB;++i){
            cin>>aux;
            fA.push_back(aux+ftA);
        }
        fB.clear();
        fB.reserve(numBtoC);
        for(int i=0;i<numBtoC;++i){
            cin>>aux;
            fB.push_back(aux);
        }
        lw=fB.begin();
        ma=0;
        if(numAtoB<=k||numBtoC<=k){
            cout<<"-1\n";
            break;
        }
        for(int i=0;i<numAtoB;++i){
            aux=checktime(i);
            if(aux==0) break;
            if(aux==-1){
                ma=-1;
                break;
            }
            ma=max(ma,aux);
        }
        if(ma==-1) cout<<"-1\n";
        else cout<<ma+ftB<<"\n";
        
    }
    
    return 0;
}

