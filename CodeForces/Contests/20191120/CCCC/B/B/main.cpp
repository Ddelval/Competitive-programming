//  B
//	main.cpp
//  Created by David del Val on 01/11/2019
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


int main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    int n;
    int a,b,c;
    string s;
    while(q--){
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        vector<char> vc=vector<char>(n);
        for(int i=0;i<n;++i){
            char ac=s[i];
            if     (ac=='S'&&a>0){vc[i]='R';a--;}
            else if(ac=='R'&&b>0){vc[i]='P';b--;}
            else if(ac=='P'&&c>0){vc[i]='S';c--;}
        }
        for(int i=0;i<n;++i){
            if(vc[i])continue;
            if(a>0){vc[i]='R';a--;}
            else if(b>0){vc[i]='P';b--;}
            else if(c>0){vc[i]='S';c--;}
        }
        int wins=0;
        for(int i=0;i<n;++i){
            if(vc[i]=='R'&&s[i]=='S')wins++;
            if(vc[i]=='P'&&s[i]=='R')wins++;
            if(vc[i]=='S'&&s[i]=='P')wins++;
        }
        if(wins>=ceil(n/2.0)){
            cout<<"YES\n";
            for(int i=0;i<n;++i)cout<<vc[i];
            cout<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}


