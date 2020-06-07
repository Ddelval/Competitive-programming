//  E2.cpp
//  Created by David del Val on 07/06/2020
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
const int bitsize=6;
#else
// Judge constraints
const int bitsize=62;
#endif
int n;
vl dat;

bool possible_sum(vector<vi> elements){
    map<int,int> pos;
    for(int i=0;i<n;++i){
        
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    
    cin>>n;
    dat=vl(n);
    for(int i=0;i<n;++i)cin>>dat[i];
    map<int,vector<int>> m;
    for(int i=0;i<n;++i){
        for(int j=0;j<bitsize;++j){
            if(dat[i] & (1LL<<j))m[j].pb(i);
        }
    }




    return 0;
}