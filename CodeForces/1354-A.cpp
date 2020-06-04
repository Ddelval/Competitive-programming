//  1354-A.cpp
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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        
        if(a<=b){
            cout<<b<<"\n";
            continue;
        }

        if(c<=d){
            cout<<"-1\n";
            continue;
        }

        ll res=b;
        ll rem=a-b;
        //cout<<rem<<" "<<ll(ceil((double(rem))/(c-d)))<<"\n";
        res+=ll(ceil((double(rem))/(c-d)))*c;
        cout<<res<<"\n";

    }


    return 0;
}