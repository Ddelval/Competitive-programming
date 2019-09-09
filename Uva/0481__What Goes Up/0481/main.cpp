// UVa Online Judge 481: What Goes Up
//  0481
//	main.cpp
//  Created by David del Val on 14/08/2019
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
inline int _gcd(int a, int b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> LIS(vi&a){
	vi P(a.size());
	vi M(a.size()+1);
	int L=0;
	for(int i=0;i<a.size();++i){
		int lo=0;
		int hi=L+1;
		while (lo+1<hi){
			int mid=(lo+hi)/2;
			
			if(a[M[mid]]<a[i]) lo=mid;
			else hi=mid;
		}
		int newL=lo+1;
		P[i]=M[newL-1];
		M[newL]=i;
		if(newL>L){
			L=newL;
		}
	}
	vi S(L);
	int k=M[L];
	for(int i=L-1;i>=0;--i){
		S[i]=a[k];
		k=P[k];
	}
	return S;
}

int main(){
    ios::sync_with_stdio(false);
	vi dat;
	int a;
	while(cin>>a){
		dat.pb(a);
	}
	vi s=LIS(dat);
	cout<<s.size()<<"\n"<<"-"<<"\n";
	for(int a:s){
		cout<<a<<"\n";

	}
    return 0;
}

