//  E.cpp
//  Created by David del Val on 18/06/2020
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

int f(int node, vector<pii>& adyList,bool havetoClose,vector<vector<int>>& dp){
    if(node==-1)return 0;
    if(dp[node][havetoClose]!=-1)return dp[node][havetoClose];
    if(havetoClose){
        return 1+f(adyList[node].fi,adyList,false,dp)+f(adyList[node].se,adyList,false,dp);
    }
    else{
        int c1=1+f(adyList[node].fi,adyList,false,dp)+f(adyList[node].se,adyList,false,dp);
        int c2=f(adyList[node].fi,adyList,true,dp)+f(adyList[node].se,adyList,true,dp);
        return min(c1,c2);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<int>>children(n,vi());
        int a,b;
        for(int i=0;i<m;++i){
            cin>>a>>b;
            a--;
            b--;
            
            children[a].pb(b);
        }
        vector<pii> pairs(n);
        for(int i=0;i<n;++i){
            if(children[i].size()==0)pairs[i]={-1,-1};
            else if(children[i].size()==1)pairs[i]={children[i][0],-1};
            else pairs[i]={children[i][0],children[i][1]};
        }
        vector<int> v={-1,-1};
        vector<vector<int>> dp=vector<vector<int>>(n,v);
        ll close=f(0,pairs,false,dp);
        cout<<close<<"\n";
    }
    return 0;
}