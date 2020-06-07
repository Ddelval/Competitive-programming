//  1350-C.cpp
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

#else
// Judge constraints
#endif

ll n;
vl dat;
const int siz=200010;
char siev[siz];

void sieve(int n){
    for(ll i=2;i<=n;++i){
        if(siev[i])continue;
        for(ll j=i*i;j<=n;j+=i){
            //cout<<j<<endl;
            siev[j]=true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n;
    dat=vl(n);
    ll ma=-1;
    for(int i=0;i<n;++i){
        cin>>dat[i];
        ma=max(ma,dat[i]);
    }
    
    sieve(ma);
    vl primes;
    for(int i=2;i<=ma;++i){
        if(!siev[i])primes.push_back(i);
    }
    //cout<<"hi"<<endl;
    ll res=1;
    for(auto p:primes){
        vi ks;
        int count=0;
        for(auto a:dat){
            int k=0;
            while(a%p==0){
                k++;
                a/=p;
            }
            if(k==0){
                count++;
            }
            ks.pb(k);
            if(count==2)break;
        }
        if(count==2)continue;
        nth_element(ks.begin(),ks.begin()+1,ks.end());
        res*=ll(pow(p,ks[1]));
        
    }
    cout<<res<<"\n";
    return 0;
}