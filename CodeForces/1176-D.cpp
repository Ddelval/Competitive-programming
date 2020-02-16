//
//  main.cpp
//  1176-D
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

#define L 2750132
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<int> primes;
vector<int> b;
bool prim[L];
bool isPrime(int n){
    for(int i=2;i<=sqrt(n);++i){
        if(!(n%i)) return false;
    }
    prim[n]=true;
    return true;
}
void fullPrimes(){
    for(int i=2;i<L;++i){
        if(isPrime(i))primes.push_back(i);
    }
}
int mcd(int n){
    for(int i=2;i<=sqrt(n);++i){
        if(!(n%i)) return n/i;
    }
    return n;
}

int arr[L];


int main(){
    ios::sync_with_stdio(false);
    primes.reserve(200000);
    fullPrimes();
    int n;
    while(cin>>n){
        n*=2;
        int a;
        for(int i=0;i<n;++i){
            cin>>a;
            arr[a]++;
        }
        for(int j=L-1;j>=0;j--){
            if(arr[j]){
                if(!prim[j]){
                    arr[mcd(j)]-=arr[j];
                }
            }
        }
        for(int j=1;j<L;++j){
            if(arr[j]){
                if(prim[j]){
                    arr[primes[j-1]]-=arr[j];
                }
            }
        }
        bool b=false;
        for(int i=1;i<L;++i){
            if(arr[i]){
                for(int j=0;j<arr[i];++j){
                    if(!b){
                        cout<<i;
                        b=true;
                    }
                    else{
                        cout<<" "<<i;
                    }
                }
            }
        }
    }
    
    
    return 0;
}
