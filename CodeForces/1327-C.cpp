//  1327-C.cpp
//  Created by David del Val on 12/04/2020
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
    int n,m,k;
    cin>>n>>m>>k;
    cout<<n+m-2+(((n/2))*(m-1+m-1+2))+n%2*(m-1)<<"\n";
    for(int i=0;i<m-1;++i)cout<<"R";
    for(int i=0;i<n-1;++i)cout<<"D";
    for(int i=0;i<(n/2)*2;i+=2){
        for(int j=0;j<m-1;++j)cout<<"L";
        cout<<"U";
        for(int j=0;j<m-1;++j)cout<<"R";
        cout<<"U";
    }
    if(n%2){
         for(int j=0;j<m-1;++j)cout<<"L";
    }
    cout<<"\n";
    
    return 0;
}