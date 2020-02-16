//  1195-D2
//	main.cpp
//  Created by David del Val on 18/07/2019
//
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <string.h>
#include <limits.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}

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
inline int _gcd(int a, int b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define CT 998244353
#define lim 100005

int lengths[11];
string dat[lim];
ll calculate(string a,int cif){
	ll res=0;
	ll po=1;
	ll cnt=0;
	for(int i=(int)a.length()-1;i>=0;--i){
		res+=((a[i]-'0')*po)%CT;
		res%=CT;
		po*=10;
		po%=CT;
		if(cnt<cif)po*=10;
		po%=CT;
		cnt++;
	}
	po=10;
	cnt=1;
	for(int i=(int)a.length()-1;i>=0;--i){
		res+=((a[i]-'0')*po)%CT;
		res%=CT;
		po*=10;
		po%=CT;
		if(cnt<cif)po*=10;
		po%=CT;
		cnt++;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>dat[i];
		lengths[dat[i].length()]++;
	}
	ll res=0;
	
	for(int i=0;i<n;++i){
		for(int j=1;j<11;++j){
			if(lengths[j]){
				res+=(calculate(dat[i], j)*lengths[j])%CT;
				res%=CT;
			}
		}
	}
	cout<<res;
	
	return 0;
}

