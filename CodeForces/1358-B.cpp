//  1358-B.cpp
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


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>dat(n);
        int a;
        for(int i=0;i<n;++i){
            cin>>dat[i];
        }
        sort(all(dat));
        int count=1;
        int buffer=0;
        for(int i=0;i<n;++i){
            if(count+buffer>=dat[i]){
                count+=buffer+1;
                buffer=0;
            }
            else{
                buffer++;
            }
        }
        cout<<count<<"\n";
    }
    
    return 0;
}