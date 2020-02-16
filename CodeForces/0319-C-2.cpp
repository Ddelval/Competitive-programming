//  0319-C
//	main.cpp
//  Created by David del Val on 01/09/2019
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

struct Line{
	mutable ll m,n,p; // mutable:To be able to assign values to the iterators;
	/*
	 m: slope
	 n: intersection with y axis
	 p: intersection with the next line
	 */
	bool operator < (const Line& l)const{return m<l.m;}
	bool operator < (ll x) const {return p<x;}
};
struct lineContainer: multiset<Line,less<>>{
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	/**
	 Calculates the intersection point with the next line
	 Returns false when there is no more lines to delete
	 */
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; } // There are no more lines to the right
		if (x->m == y->m) x->p = x->n > y->n ? inf : -inf; // Parallel lines
		else x->p = div(y->n - x->n, x->m - y->m); // General case
		return x->p >= y->p; //Check if the line is not useful
	}
	void add(ll m, ll n) {
		auto z = insert({m, n, 0}), y = z++, x = y;
		//Remove useless to the right
		while (isect(y, z)) z = erase(z);
		//Calculate intersection with the previous function
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		//Remove useless to the left
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll querry(ll x){
		auto l=*lower_bound(x);
		return l.m*x+l.n;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vii dat;
	int a,b;
	REP(i,n){
		cin>>a;
		dat.pb(mp(a,0));
	}
	REP(i,n){
		cin>>b;
		dat[i].se=b;
	}
	ll cost=0;
	lineContainer da;
	da.add(-dat[0].se,0);
	for(int i=1;i<n;++i){
		cost=-da.querry(dat[i].fi);
		da.add(-dat[i].se,-cost);
	}
	cout<<cost;
	
	return 0;
}


