//  D
//    main.cpp
//  Created by David del Val on 27/12/2019
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
#define LSB(x) ((x) & (-(x)))
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}
#define REPO(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) for(int i=0;i<b;i++)
 
void ECHO(string _s){cout<<endl;(void)_s;}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    unsigned _i; string _s2="";
    for(_i=0;_i<_s.length();++_i){if(_s[_i]==',')break;if(_s[_i]!=' ')_s2+=_s[_i];}
    if(_i==_s.length()){--_i;}cout<<"  ("<<_s2<<"):"<<x;
    ECHO(_s.substr(_i+1, _s.length()-_i-1), args...);
}
 
 
template<typename T0, typename T1>
inline ostream& operator << (ostream& os, pair<T0, T1>& p){
    return os << "(" << p.first << ", " << p.second <<")";
}
 
template <typename T>
inline ostream& operator << (ostream& os, vector<T>& v){
    for(unsigned i = 0; i < v.size(); ++i){cout << v[i] << "_";}cout<<endl;
    return os;
}
 
template<typename T> inline T _min(T x1, T x2, T x3){return min(x1, min(x2, x3));}
template<typename T> inline T _min(T x1, T x2, T x3, T x4){return min(min(x1, x2), min(x2, x3));}
 
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define mod 998244353ll
 
 
 
  ll power(ll x, ll y, ll m)
  {
      if (y == 0)
          return 1;
      ll p = power(x, y/2, m) % m;
      p = (p * p) % m;
    
      return (y%2 == 0)? p : (x * p) % m;
  }
 
ll modInverse(ll a, ll m)
{
    return power(a, m-2, m);
    
}
  
pll sum(pll a1, pll a2){
    if(a1==mp(0ll,0ll))return a2;
    pll res;
    res.fi=(a1.fi*a2.se)%mod+(a2.fi*a1.se)%mod;
    res.fi%=mod;
    res.se=(a2.se*a1.se)%mod;
    ll b;
    while((b=_gcd(res.fi, res.se))&&b!=1){
        res.fi/=b;
        res.se/=b;
    }
    return res;
}
 
 
 
int main(){
    ios::sync_with_stdio(false);
    ll n;
    int a;
    ll k;
    cin>>n;
    map<int,pll>ma;
    map<int,ll>occ;
    for(int i=0;i<n;++i){
        cin>>k;
        for(int j=0;j<k;++j){
            cin>>a;
            occ[a]++;
            if(ma.count(a)==0){
                ma[a]={1,k};
            }
            else{
                ma[a]=sum(ma[a], {1,k});
            }
        }
    }
    pll tot={0,0};
    ll a1,a2;
    for(auto aaa:ma){
        a1=(aaa.se.fi%mod*(occ[aaa.fi])%mod)%mod;
        a2=(aaa.se.se*((n)%mod*n%mod)%mod)%mod;
        tot=sum(tot,{a1,a2});
    }
    ll total=tot.se;
    ll possible=tot.fi;
    
    ll y=modInverse(total,mod);
    cout<<(possible*y)%mod<<"\n";
 
    return 0;
}
