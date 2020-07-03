//  C.cpp
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
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vi as(n);
        for(int i=0;i<n;++i)cin>>as[i];
        vi ws(k);
        for(int i=0;i<k;++i)cin>>ws[i];
        sort(all(as));
        reverse(all(as));
        sort(all(ws));
        vi ma(k, INT_MIN);
        vi mi(k,INT_MAX);
        int counter=0;
        for(int i=0;i<k;++i){
            ma[i]=as[counter];
            counter++;
        }
        for(int i= 0;i<k;++i){
            if(ws[i]>1){
                mi[i]=as[counter+ws[i]-2];
                counter+=ws[i]-1;
            }
            else{
                mi[i]=ma[i];
            }
            
        }
        //cout<<mi<<endl;
        //cout<<ma<<endl;
        ll res=0;
        for(int i=0;i<k;++i){
            res+=ma[i]+mi[i];
        }
        cout<<res<<endl;

    }
    
    return 0;
}