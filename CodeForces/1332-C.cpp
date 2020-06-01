//  1332-C.cpp
//  Created by David del Val on 10/04/2020
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<map<char,int>> ocurr(k, map<char,int>());
        for(int i=0;i<s.length();++i){
            ocurr[i%k][s[i]]++;
        }
        
        for(int i=0;i<k/2;++i){
            for(auto b: ocurr[k-i-1]){
                ocurr[i][b.first]+=b.second;
            }
        }
        int changes=0;
        for(int i=0;i<k/2;++i){
            int ma=-1;
            for(auto b:ocurr[i]){
                ma=max(ma,b.se);
            }
            changes+=(2*(n/k)-ma);
        }
        if(k%2==1){
            int ma=-1;
            for(auto b:ocurr[k/2]){
                ma=max(ma,b.se);
            }
            changes+=((n/k)-ma);
        }
        cout<<changes<<"\n";

    }
    
    return 0;
}