//  1250-A.cpp
//  Created by David del Val on 06/06/2020
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
inline pii operator + (pii a, pii b){
    return {a.fi+b.fi,a.se+b.se};
}

inline ostream& operator << (ostream& o, pii p){
    o<<p.fi<<" "<<p.se;
    return o;
}

template<typename>
struct is_std_vector : std::false_type {};
template<typename T, typename A>
struct is_std_vector<std::vector<T,A>> : std::true_type {};

template <typename T>
inline ostream& operator << (ostream& o, vector<T> &p){
    for(int i=0;i<p.size();++i){
        o<<setw(3)<<p[i];
        if(is_std_vector<T>::value)o<<"\n";
    }
    return o;
}



#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

ll val(ll n){
    ll div=-1;
    for(ll i=2;i<=sqrt(n);++i){
        if(n%i==0){
            div=i;
            break;
        }
    }
    if(div==-1)div=n;
    return div;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n%2==0)cout<<n+2*k<<"\n";
        else cout<<n+2*(k-1)+val(n)<<"\n";
    }
    
    return 0;
}