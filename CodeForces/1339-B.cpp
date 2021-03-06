//  1339-B.cpp
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
        o<<" "<<setw(3)<<p[i];
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
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi dat(n);
        for(int i=0;i<n;++i)cin>>dat[i];
        sort(all(dat));
        vi dat2;
        vi a1,a2;
        for(int i=0;i<n/2;++i){
            a1.pb(dat[i]);
        }
        for(int i=n-1;i>=n/2;--i){
           a2.pb(dat[i]);
        }
        auto it1=a1.begin();
        auto it2=a2.begin();
        while(it1!=a1.end() || it2!=a2.end()){
            if(it1!=a1.end()){
                dat2.pb(*it1);
                it1++;
            }
            if(it2!=a2.end()){
                dat2.pb(*it2);
                it2++;
            }
        }
        reverse(all(dat2));
        for(int i=0;i<n; ++i){
            if(i)cout<<" ";
            cout<<dat2[i];
        }
        cout<<"\n";
    }
    
    return 0;
}