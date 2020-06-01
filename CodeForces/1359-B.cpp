//  1359-B.cpp
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

ll n,m,x,y;
ll calculate_prize(ll len){
    return min(x*len,len/2*y+(len%2)*x);
}

int main(){
    
    ll t;
    cin>>t;
    while(t--){
        ll cost=0;
        cin>>n>>m>>x>>y;
        for(int i=0;i<n;++i){
            int seq=0;
            char c;
            for(int j=0;j<m;++j){
                cin>>c;
                if(c=='.')seq++;
                if(c=='*'){
                    cost+=calculate_prize(seq);
                    seq=0;
                }
            }
            cost+=calculate_prize(seq);
        }
        cout<<cost<<"\n";
    }

    
    return 0;
}