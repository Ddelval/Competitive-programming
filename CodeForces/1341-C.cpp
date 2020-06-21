//  1341-C.cpp
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

const int lim=1e5+10;
int perm[lim];
int pos[lim];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i)cin>>perm[i];

        for(int i=0;i<n;++i){
            pos[perm[i]-1]=i;
        }
        vector<pii> segms;
        pii d{-1,-1};
        for(int i=0;i<n;++i){
            if(d.fi==-1){
                d.fi=pos[i];
                d.se=pos[i];
                continue;
            }
            if(pos[i]==pos[i-1]+1){
                d.se=pos[i];
            }
            else{
                segms.push_back(d);
                d={pos[i],pos[i]};
            }
        }
        segms.push_back(d);
        //cout<<segms<<endl;
        bool bad=false;
        for(int i=1;i<segms.size();++i){
            if(segms[i].se-segms[i-1].fi!=-1){
                bad=true;
            }
        }
        if(bad)cout<<"No\n";
        else cout<<"Yes\n";
    }
    
    return 0;
}