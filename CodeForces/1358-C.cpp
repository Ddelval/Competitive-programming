//  1358-C.cpp
//  Created by David del Val on 02/06/2020
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

ll combinat(ll up, ll down){
    ll accum=up;
    if(down==0)return 1;
    for(int i=2;i<=down;++i){
        accum*=(up-(i-1));
        accum/=i;
    }
    return accum;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll hdiff=x2-x1;
        ll vdiff=y2-y1;
        cout<<(hdiff)*vdiff+1<<"\n";
    }
    return 0;
}