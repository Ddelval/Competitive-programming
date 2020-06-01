//  1327-E.cpp
//  Created by David del Val on 12/04/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;



int main(){
    int n;
    cin>>n;
    ll b;
    ll mod=998244353;
    ll aux=1;
    vector<ll> dat;
    for(int i=n;i>0;--i){
       ll res=0;
       if(n-(i-1)-2>=0){
            res+=10*9*9;
            res*=n-(i-1)-2;
            res*=aux;
            res%=mod;
            res*=299473306;
            res%=mod;
            
       }
       if(i!=n){
           res+=2*(10*9*aux)%mod;
           res%=mod;
           aux*=10;
           aux%=mod;
       }
       else{
           res+=10;
       }

        dat.push_back(res);
       
    }
    for(int i=n-1;i>=0;--i){
        cout<<dat[i];
        if(i)cout<<" ";
    }
    cout<<"\n";
    return 0;
}