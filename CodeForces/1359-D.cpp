//  1359-D.cpp
//  Created by David del Val on 01/06/2020
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
    vi dat(n);
    bool pos=true;
    bool neg=true;
    for(int i=0;i<n;++i){
        cin>>dat[i];
        
    }
    ll ans=0;
    for(int i=0;i<=30;++i){
        ll curr=0;
        ll best=0;
        for(int val:dat){
            if(val>i){
                curr=0;
                continue;
            }
            curr+=val;
            if(curr<0)curr=0;
            best=max(curr,best);
        }
        ans=max(best-i,ans);
    }
    cout<<ans<<"\n";
    return 0;
}