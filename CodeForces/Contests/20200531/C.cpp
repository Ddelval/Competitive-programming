//  C.cpp
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
        int n;
        int x;
        cin>>n>>x;
        int deg=0;
        int a,b;
        for(int i=0;i<n-1;++i){
            cin>>a>>b;
            if(a==x||b==x)deg++;
        }
        if(deg<=1){
            cout<<"Ayush\n";
            continue;
        }
        if((n-3)%2==1){
            cout<<"Ayush\n";
            continue;
        }
        else{
            cout<<"Ashish\n";
            continue;
        }
    }
    return 0;
}