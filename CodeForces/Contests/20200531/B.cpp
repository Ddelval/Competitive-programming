//  B.cpp
//  Created by David del Val on 31/05/2020
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
    for(int w=0;w<t;++w){
        string s;
        cin>>s;
        int ot=0;
        int ut=0;
        for(char c:s){
            if(c=='0')ot++;
            else ut++;
        }
        int uc=0;
        int oc=0;
        int cost=min(ot,ut);
        for(int i=0;i<s.length();++i){
            if(s[i]=='0')oc++;
            else uc++;

            int ncost=min(oc+(ut-uc), uc+(ot-oc));
            cost=min(cost,ncost);

        }
        cout<<cost<<"\n";
    }
    
    return 0;
}