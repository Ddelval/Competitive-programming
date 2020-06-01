//  1359-C.cpp
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

ll h,c,t;
ll fun(ll n){
    return (n*c+(n+1)*h);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        
        cin>>h>>c>>t;
        if(t<=(h+c)/2){
            cout<<"2\n";
            continue;
        }
        if(t>=h){
            cout<<"1\n";
            continue;
        }
        double guess=((double)t-h)/(c+h-2*t);
        ll dec=(ll)guess;

        ll lval=(fun(dec)-t*(2*dec+1))*(2*(dec+1)+1);
        ll rval=(fun(dec+1)-t*(2*(dec+1)+1))*(2*(dec)+1);
        if(abs(lval)>abs(rval)){
            dec++;
        }
        cout<<2*dec+1<<"\n";
    }
    
    return 0;
}