// UVa Online Judge 166: Making Change
//  0166
//	main.cpp
//  Created by David del Val on 15/08/2019
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

vi rem[1001];
int change[1001];
int ret[1001];
int val[6]={1,2,4,10,20,40};

void precalc(){
	for(int i=1;i<=1000;++i){
		int mi=INT_MAX;
		for(int j=0;j<6;++j){
			if(i-val[j]>=0) mi=min(mi,ret[i-val[j]]+1);
			else break;
		}
		ret[i]=mi;
	}
}


int main(){
    ios::sync_with_stdio(false);
	int a,b,c,d,e,f;
	int dd,ddd;
	precalc();
	while(cin>>a>>b>>c>>d>>e>>f&&(a||b||c||d||e||f)){
		char cha;
		cin>>dd>>cha>>ddd;
		int amm=(ddd+dd*100)/5;
		change[0]=0;
		vi ini;
		ini.pb(a); ini.pb(b); ini.pb(c); ini.pb(d); ini.pb(e); ini.pb(f);
		int lim=a+2*(b+2*c+5*(d+2*(e+f*2)));
		rem[0]=ini;
		for(int i=1;i<=1000;++i){
			int mi=INT_MAX/2;
			vi re=rem[i-1];
			for(int j=0;j<6;++j){
				if(i-val[j]>=0){
					if(change[i-val[j]]!=INT_MAX/2&&mi>1+change[i-val[j]]&&rem[i-val[j]][j]){
						mi=1+change[i-val[j]];
						re=rem[i-val[j]];
						re[j]--;
					}
				}else break;
			}
			change[i]=mi;
			rem[i]=re;
		}
		int mi=INT_MAX/2;
		for(int i=amm;i<=lim;i++){
			mi=min(mi,change[i]+ret[i-amm]);
		}
		
		printf("%3d\n",mi);
		
	}

    return 0;
}


