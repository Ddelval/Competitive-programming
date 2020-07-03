//  E.cpp
//  Created by David del Val on 23/06/2020
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


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    vi ws(n);
    map<int,pii> mapp;
    vector<pii> rawdat;
    for(int i=0;i<n;++i)cin>>ws[i];
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        mapp[i]=pii{ws[min(a,b)-1],ws[max(b,a)-1]};
        rawdat.pb({a-1,b-1});
    }
    vi ord;
    for(int i=0;i<m;++i)ord.pb(i);
    sort(all(ord),[&](int i, int j){
        return mapp[i]<mapp[j];
    });
    
    bool failed=false;
    for(int j=0;j<m;++j){
        int i=ord[j];
        int eaten=0;
        if(ws[rawdat[i].fi]>0){
            eaten++;
            ws[rawdat[i].fi]--;
        }
        if(ws[rawdat[i].se]>0){
            eaten++;
            ws[rawdat[i].se]--;
        }
        if(!eaten){
            failed=true;
            break;
        }
    }
    if(failed){
        cout<<"DEAD\n";
    }
    else{
        cout<<"ALIVE\n";
        for(int i=0;i<m;++i){
            if(i)cout<<" ";
            cout<<ord[i]+1;
        }
        cout<<"\n";
    }
    
    return 0;
}