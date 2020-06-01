//  1337-D.cpp
//  Created by David del Val on 16/04/2020
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

ll findoptimal(vl &les, vl &eq, vl &sup){
    ll diff=LLONG_MAX;
    for(ll val:eq){
        ll z= *lower_bound(les.begin(),les.end(),val);
        if(lower_bound(les.begin(),les.end(),val)==les.end())continue;
        ll x=*lower_bound(sup.rbegin(),sup.rend(),val,greater<ll>());
        if(lower_bound(sup.rbegin(),sup.rend(),val,greater<ll>())==sup.rend())continue;
        //cout<<z<<" "<<val<<" "<<x<<"\n";
        ll ndif=pow(x-val,2)+pow(x-z,2)+pow(val-z,2);
        diff=min(diff,ndif);
    }
    return diff;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int nr,ng,nb;
        cin>>nr>>ng>>nb;
        vl r(nr),g(ng),b(nb);
        for(int i=0;i<nr;++i) cin>>r[i];
        for(int i=0;i<ng;++i) cin>>g[i];
        for(int i=0;i<nb;++i) cin>>b[i];
        
        sort(all(r));
        sort(all(g));
        sort(all(b));

        ll sol=findoptimal(r,g,b);
        sol=min(sol,findoptimal(r,b,g));
        sol=min(sol,findoptimal(g,b,r));
        sol=min(sol,findoptimal(g,r,b));
        sol=min(sol,findoptimal(b,r,g));
        sol=min(sol,findoptimal(b,g,r));

        cout<<sol<<"\n";
    }
    
    return 0;
}