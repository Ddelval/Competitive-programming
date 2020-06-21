//  1334-D.cpp
//  Created by David del Val on 20/06/2020
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
ll n,l,r;
void addcase(int index,int n, vi& vec){

    for(int c=index+1;c<=n;++c){
        vec.pb(index);
        vec.pb(c);
    }
}
void gencases(vi& data, ll & ir){
    ll start=1;
    ll end=2*(n-1);
    ir=-1;
    for(int i=0;i<=n-1;++i){
        if((start>=l && start<=r)|| (end>=l && end<=r) || (start<=l && end>=r)){
            if(ir==-1)ir=start;
            addcase(i+1,n,data);
        }
        start+=2*(n-i-1);
        end  +=2*(n-i-2);
    }
    if(ir==-1)ir=end+1;
    data.pb(1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
       cin>>n>>l>>r;
       vi data;
       ll sindex;
       gencases(data,sindex);
       bool b=false;
       for(ll i=l-sindex;i<=r-sindex;++i){
           if(b)cout<<" ";
           cout<<data[i];
           b=true;
       }
       cout<<"\n";
    }
    
    return 0;
}