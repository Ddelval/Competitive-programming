//
//  main.cpp
//  1173-C
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
int        hand[200005];
int        pile[200005];
bool cardinpile[200005];
int   posofcard[200005];
int n;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        for(int i=0;i<n;++i){
            cin>>hand[i];
            cardinpile[hand[i]]=false;
            posofcard[hand[i]]=i;
        }
        for(int i=0;i<n;++i){
            cin>>pile[i];
            cardinpile[pile[i]]=true;
            posofcard[pile[i]]=i;
        }
        if(cardinpile[1]==false){
            int wait=0;
            for(int i=0;i<n;++i){
                if(pile[i]&&pile[i]<=i+1){
                    wait=max(wait, i-pile[i]+2);
                }
            }
            cout<<n+wait<<"\n";
            continue;
        }
        bool inonego=true;
        int expcard=1;
        for(int i=posofcard[1];i<n;++i){
            if(pile[i]!=expcard){
                inonego=false;
                break;
            }
            expcard++;
        }
        
        if(inonego){
            for(int i=0;i<posofcard[1];++i){
                if(pile[i]&&pile[i]<=pile[n-1]+1+i){
                    inonego=false;
                }
            }
            if(inonego){
                cout<<posofcard[1]<<"\n";
                continue;
            }
        }
        int wait=0;
        for(int i=posofcard[1];i<n;++i){
            if(pile[i]&&pile[i]<=i-posofcard[1]){
                wait=max(wait, i-posofcard[1]+1-pile[i]);
            }
        }
        cout<<posofcard[1]+1+wait+n<<"\n";
    }
    return 0;
}
