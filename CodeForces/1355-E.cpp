//  1355-E.cpp
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

const int siz=200000;
ll pillars[siz];
ll presum[siz];
ll n,a,r,m;
int totalBlocks;
ll cost(ll target){
    int pos=lower_bound(pillars,pillars+n,target)-pillars;
    //cout<<it<<" ";
    ll toAdd=target*pos-presum[pos];
    ll toRemove=(presum[n]-presum[pos])- target*(n-pos);

    //cout<<toAdd<<" "<<toRemove<<" ";
    ll res=min(toAdd,toRemove);
    toAdd-=res;
    toRemove-=res;
    res=res*m+toAdd*a+toRemove*r;
    //cout<<target<<" "<<res<<"\n";
    return res;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n>>a>>r>>m;
    m=min(m,a+r);
    for(int i=0;i<n;++i){
        cin>>pillars[i];
    }
    sort(pillars,pillars+n);
    for(int i=0;i<n;++i){
        presum[i+1]=pillars[i]+presum[i];
    }

    ll res=LLONG_MAX/10;
    for(int i=0;i<n;++i){
        res=min(res,cost(pillars[i]));
    }
    res=min(res,cost(presum[n]/n));
    res=min(res,cost(presum[n]/n+1));
    cout<<res<<"\n";
    return 0;
}