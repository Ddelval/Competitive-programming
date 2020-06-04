//  1354-B.cpp
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
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll ind[]{-1,-1,-1};
        ll n= s.length();
        ll ma=-1;
        ll mi=LLONG_MAX/2;
        for(int i=0;i<n;++i){
            ind[s[i]-'1']=i;
            //cout<<" "<<ind[0]<<" "<<ind[1]<<" "<<ind[2]<<"\n";
            ll mmi=*min_element(ind,ind+3);
            if(mmi!=-1){
                mi=min(mi,i-mmi+1);
            }
        }
        if(mi==LLONG_MAX/2)cout<<"0\n";
        else cout<<mi<<"\n";
    }
    
    return 0;
}