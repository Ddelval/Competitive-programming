//  1332-A.cpp
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

bool filter(int x1,int x2,int a, int b){
    if(x2-x1>0){
        if(a>=b){
            if(a-b>-x1){
                return false;
            }
        }
        else{
            if(b-a>x2){
                return false;
            }
        }
    }
    else{
        if(a||b){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        int x,y,x1,y1,x2,y2;
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        x1-=x;
        x2-=x;
        y1-=y;
        y2-=y;
        if(!filter(x1,x2,a,b) || !filter(y1,y2,c,d)){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        
    }
    
    return 0;
}