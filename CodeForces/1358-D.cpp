//  1358-D.cpp
//  Created by David del Val on 03/06/2020
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
    
    ll n,x;
    cin>>n>>x;
    vl days(n);
    for(int i=0;i<n;++i)cin>>days[i];
    for(int i=0;i<n;++i){
        days.pb(days[i]);
    }
    vl sums(2*n);
    vl presum(2*n);
    presum[0]=0;
    vl count(2*n);
    count[0]=0;
    for(int i=0;i<2*n;++i){
        sums[i]=((days[i]*(days[i]+1))/2);
        if(i!=0)presum[i]=sums[i]+presum[i-1];
        else presum[i]=sums[i];
        if(i!=0)count[i]=count[i-1]+days[i];
        else count[i]=days[i];
    }
    ll res=0;
    /*
    cout<<"sums:\t";
    for(auto a: sums)cout<<a<<" ";
    cout<<"\n";
    cout<<"presum:\t";
    for(auto a: presum)cout<<a<<" ";
    cout<<"\n";
    cout<<"count:\t";
    for(auto a: count)cout<<a<<" ";
    cout<<"\n";
*/
    for(int i=0;i<2*n;++i){
        if(count[i]<x)continue;
        ll curr=presum[i];
        auto it = upper_bound(all(count),count[i]-x);
        int index=it-count.begin();
        //cout<<i<<" "<<index<<endl;
        
            curr-=presum[index];
            ll restan=count[index]-(count[i]-x);
            
            ll quitar=days[index]-restan;
            //cout<<restan<<" "<<quitar<<" ";
            curr+=sums[index]-(quitar*(quitar+1))/2;
        
        //cout<<curr<<endl<<endl;
        res=max(res,curr);
    }
    cout<<res<<"\n";


    return 0;
}