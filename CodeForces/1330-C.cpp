//  1330-C.cpp
//  Created by David del Val on 09/04/2020
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
    int n,m;
    cin>>n>>m;
    vi dat(m);
    for(int i=0;i<n;++i){
        cin>>dat[i];
    }
    bool posible=true;
    int cursor=n;
    vi pos;
    for(int i=m-1;i>=0;--i){
        cursor=min(cursor-1,n-dat[i]);
        pos.pb(cursor);
        if(cursor<0){
            posible=false;
            break;
        }
    }
    if(!posible){
        cout<<"-1\n";
        return 0;
    }
    reverse(pos.begin(),pos.end());
    cursor=0;
    for(int i=0;i<m;++i){
        if(cursor>=pos[i]){
            cursor=n;
            break;
        }
        pos[i]=cursor;
        cursor+=dat[i];
    }
    if(cursor<n){
        cout<<"-1\n";
        return 0;
    }

    for(int i=0;i<m;++i){
        if(i)cout<<" ";
        cout<<pos[i]+1;
    }
    cout<<"\n";
    return 0;
}