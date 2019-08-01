//
//  main.cpp
//  1174-C
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
vector<int> primes;
bool isPrime(int n){
    if(!(n%2)) return false;
    for(int i=3;i<=sqrt(n);i+=2){
        if(!(n%i)) return false;
    }
    return true;
}
void getPrimes(int lim){
    primes.clear();
    primes.push_back(2);
    for(int i=3;i<=lim;i+=2){
        if(isPrime(i)) primes.push_back(i);
    }
    //for(int i:primes)cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        getPrimes(n);
        cout<<"1";
        for(int i=3;i<=n;++i){
            for(int j=0;j<primes.size();++j){
                if(i%primes[j]==0){
                    cout<<" "<<j+1;
                    break;
                }
            }
        }
        
    }
    return 0;
}
