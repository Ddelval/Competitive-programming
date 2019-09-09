//  C
//	main.cpp
//  Created by David del Val on 30/07/2019
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
ll n,I;
bool eval(int i){
	return n*ceil(log2(i))<=I;
}

int main(){
    ios::sync_with_stdio(false);
	
	cin>>n>>I;
	I*=8;
	map<int,int> m;
	int a;
	for(int i=0;i<n;++i){
		cin>>a;
		m[a]++;
	}
	int l,r;
	l=1;
	int ans=1;
	/*
	r=(int)m.size();
	while(l<=r){
		int mid=l+(r-l)/2;
		if(l+1>=r){
			if(eval(l+1))ans=l+1;
			else ans=l;
			break;
		}
		if(eval(mid))l=mid;
		else r=mid;
	}
	 */
	ans=floor(pow(2, floor((double)I/n)));
	if(ans>=m.size()){
		cout<<"0";
		return 0;
	}
	auto it=m.begin();
	auto it2=it;
	int cmax=0;
	for(int i=0;i<ans;++i){
		cmax+=it2->se;
		it2++;
	}
	int aux=cmax;
	for(int i=ans;i<m.size();++i){
		aux+=it2->se;
		aux-=it->se;
		cmax=max(cmax,aux);
		
		it++;it2++;
	}
	cout<<n-cmax;
	
    return 0;
}

