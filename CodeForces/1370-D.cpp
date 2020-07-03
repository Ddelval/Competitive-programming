//  1370-D.cpp
//  Created by David del Val on 22/06/2020
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

vi dat;
int n,k;
bool test(ll lim,bool odd){
    //cout<<lim<<" "<<odd<<endl;
    int count=0;
    bool b=odd;
    for(int i=0;i<n;i++){
        if(b){
            count++;
            b=false;
            continue;
        }
        if(dat[i]<=lim){
            //cout<<"pick "<<dat[i]<<endl;
            b=true;
            count++;
        }
    }
   //cout<<"return: "<<(count>= (k+!odd)/2)<<endl;
   return count>= k;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    dat=vi(n);
    for(int i=0;i<n;++i)cin>>dat[i];

    ll r=1e9+10;
    ll l=0;
    while(r-l>1){
        int mid=(r+l)/2;
        if(test(mid,false) || test(mid,true)){
            r=mid;
        }
        else l=mid;
    }
    cout<<r<<"\n";

    return 0;
}