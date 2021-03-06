//  D.cpp
//  Created by David del Val on 04/06/2020
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
    vector<pii> edges;
    vector<vector<int>> adyList(n,vi());
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        a--;
        b--;
        adyList[a].pb(b);
        adyList[b].pb(a);
    }
    vi elements(n);
    for(int i=0;i<n;++i)cin>>elements[i];

    bool bad=false;
    for(int i=0;i<n;++i){
        bool contoprev=elements[i]==1;
        bool contosame=false;
        set<int> data;
        for(auto el: adyList[i]){
            if(elements[el]==elements[i]){
                cout<<"-1\n";
                return 0;
            }
            if(elements[el]<elements[i])data.insert(elements[el]);
        }
        if(data.size()!=elements[i]-1){
            cout<<"-1\n";
            return 0;
        }
    }

    vector<pii> sor;
    for(int i=0;i<n;++i){
        sor.pb({elements[i],i});
    }
    sort(all(sor));
    for(int i=1;i<n;++i){
        if(sor[i].fi-sor[i-1].fi>1){
            cout<<"-1\n";
            return 0;
        }
    }
    for(int i=0;i<n;++i){
        if(i)cout<<" ";
        cout<<sor[i].se+1;
    }
    cout<<"\n";
    return 0;
}