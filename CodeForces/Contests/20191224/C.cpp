//  C
//	main.cpp
//  Created by David del Val on 24/12/2019
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
int n,T,a,b,eas,har;;
ll grade(int ct, ll eas_m, ll hard_m){
    if(ct<eas_m*a+hard_m*b)return 0;
    else{
        ll grad = eas_m + hard_m;
        ll rem=ct-eas_m*a-hard_m*b;
        
        ll doeasy=min(rem/a,eas-eas_m);
        grad+=doeasy;
        rem-=doeasy*a;
        ll dohard=min(rem/b,har-hard_m);
        grad+=dohard;
        return grad;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    int m;
    cin>>m;
    while(m--){
        cin>>n>>T>>a>>b;
        eas=har=0;
        vi pr(n);
        for(int i=0;i<n;++i){
            cin>>pr[i];
            eas+=!pr[i];
            har+=pr[i];
        }
        
        vi mand(n);
        for(int i=0;i<n;++i)cin>>mand[i];
        
        vii tosolve;
        for(int i=0;i<n;++i){
            tosolve.pb({mand[i],i});
        }
        sort(all(tosolve));
        vector<pair<int,pii>> require;
        require.pb({tosolve[0].fi,{!pr[tosolve[0].se],pr[tosolve[0].se]}});
        for(int i=1;i<n;++i){
            auto t=require.back().se;
            int a1,a2;
            a1=!pr[tosolve[i].se];
            a2=pr[tosolve[i].se];
            while(i!=n-1&&tosolve[i].fi==tosolve[i+1].fi){
                a1+=!pr[tosolve[i+1].se];
                a2+=pr[tosolve[i+1].se];
                i++;
            }
            require.pb({tosolve[i].fi,{a1+t.fi,a2+t.se}});
        }
        ll maxgrade=0;
        
        if(require[0].fi>0)maxgrade=max(grade(require[0].fi-1,0,0),maxgrade);
        for(int i=1;i<require.size();++i){
            int ct=require[i].fi-1;
            if(ct<0) continue;
            auto r=require[i-1].se;
            maxgrade=max(grade(ct,r.fi,r.se),maxgrade);
        }
        maxgrade=max(grade(T,require.back().se.fi,require.back().se.se),maxgrade);
        cout<<maxgrade<<"\n";
    }

    return 0;
}


