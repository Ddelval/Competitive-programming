//  1301-B
//	main.cpp
//  Created by David del Val on 16/02/2020
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
#define REP(i,n) for(int i=0;i<n;i++)

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

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vl dat(n);
        for(int i=0;i<n;++i)cin>>dat[i];
        ll ma=INT_MIN;
        ll mi=INT_MAX;
        for(int i=0;i<n;++i){
            bool b=false;
            if(i)b=b||(dat[i-1]==-1);
            if(i!=n-1)b=b||(dat[i+1]==-1);
            if(dat[i]==-1)b=false;
            if(b){
                mi=min(mi,dat[i]);
                ma=max(ma,dat[i]);
            }
            
        }
        int k=(mi+ma)/2;
        int diff=0;
        for(int i=1;i<n;++i){
            int a=dat[i-1]==-1? k:dat[i-1];
            int b=dat[i]==-1? k:dat[i];
            diff=max(diff,abs(b-a));
        }
        cout<<diff<<" "<<k<<"\n";

    }
    
    return 0;
}
