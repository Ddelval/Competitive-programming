#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <limits.h>
#include <queue>
#define INF 1000000000
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
ll primes[30];
ll divisors[1000];
ll pows[30][30];
ll minim=1000000001;
void coutvector(int depth){
    ll res=1;
    for(ll i=0;i<depth;++i){
        if(divisors[i]>31) return;
        if(!pows[i][divisors[i]-2])return;
        res*=pows[i][divisors[i]-2];
        if(res>minim||res<0) return;
    }
    //cout<<res<<"\n";
    if(res<minim)minim=res;
}
void calculatedivisors(ll a,int depth){
    ll lim;
    if(a==1){
        coutvector(depth);
        return;
    }
    if(a>31) lim=31;
    else lim=a;
    for(ll i=lim;i>=2;--i){
        if(!(a%i)){
            divisors[depth]=i;
            calculatedivisors(a/i,depth+1);
        }
    }
}
bool isPrime(ll n){
    bool b=true;
    for(ll i=2;i<=sqrt(n);++i){
        if(!(n%i)){
            b=false;
            break;
        }
    }
    return b;
}
void calculateprimes(ll lim){
    ll counter=0;
    for(ll i=2;i<LONG_MAX;++i){
        if(isPrime(i)){
            primes[counter]=i;
            for(int j=0;j<30;j++){
                pows[counter][j]=pow(i,j+1);
                if(pows[counter][j]>INF||pows[counter][j]<0) break;
            }
            counter++;
            if(counter==lim) return;
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    int input;
    calculateprimes(30);
    while(cin>>input&&input){
        if(input>1344){
            cout<<"+INF\n";
            continue;
        }
        minim=1000000001;
        calculatedivisors(input,0);
        if(minim==1000000001) cout<<"+INF\n";
        else cout<<minim<<"\n";
        
    }
    
    return 0;
}
