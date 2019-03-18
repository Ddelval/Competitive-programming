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

#define LIM 1000000
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<ll> v;
vector<ll> prim;
bool isPrime(ll a){
    bool prime=true;
    ll lim=sqrt(a);
    for(auto i:prim){
        if(i>lim)break;
        if(!(a%i)){
            prime=false;
            break;
        }
        
    }
    return prime;
}

void SieveOfAtkin(int lmt) {
    if (lmt > 2)
        prim.push_back(2);
    if (lmt > 3)
        prim.push_back(3);
    bool sieve[lmt];
    for (int i = 0; i < lmt; i++)
        sieve[i] = false;
    for (int a = 1; a * a < lmt; a++) {
        for (int b = 1; b * b < lmt; b++) {
            // Main part of Sieve of Atkin
            int n = (4 * a* a) + (b * b);
            if (n <= lmt && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
            n = (3 * a * a) + (b * b);
            if (n <= lmt && n % 12 == 7)
                sieve[n] ^= true;
            n = (3 * a * a) - (b * b);
            if (a > b && n <= lmt && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
    for (int r = 5; r * r < lmt; r++) {
        if (sieve[r]) {
            for (int i = r * r; i < lmt; i += r * r)
                sieve[i] = false;
        }
    }
    for (int x = 5; x < lmt; x++)
        if (sieve[x])
            prim.push_back(x);
}
int main(){
    ios::sync_with_stdio(false);
    ll c;
    SieveOfAtkin(10000);
    
    
    int a=0,b=0;
    while(true){
        if(prim[a]*prim[a]>LIM||a>=prim.size()-1) break;
        b=0;
        c=pow(prim[a],prim[b]);
        while(c<=LIM&&b<prim.size()-1){
            v.push_back(c);
            b++;
            c=pow(prim[a],prim[b]);
        }
        a++;
    }
    sort(v.begin(),v.end());
    int cas,N;
    cin>>cas;
    for(int i=0;i<cas;++i){
        cin>>N;
        auto it=lower_bound(v.begin(), v.end(), N);
        if(it==v.begin()){
            if(*it<=N){
                cout<<*it<<"\n";
            }
            else{
                cout<<"-1\n";
            }
            
        }
        else{
            if(*it==N){
                cout<<*it<<"\n";
            }
            else{
                advance(it,-1);
                cout<<*it<<"\n";
            }
        }
    }
    return 0;
}

