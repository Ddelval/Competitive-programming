//  1208-D
//	main.cpp
//  Created by David del Val on 26/08/2019
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
pll tree[800000];
ll lazy[800000];
ll dat[200000];
pll merge(pll a,pll b){
	if(b.se<=a.se)return b;
	return a;
}
void build(int k,int l,int r){
	if(r==l){
		tree[k]=mp(l,dat[l]);
		return;
	}
	int mid=(r+l)/2;
	build(2*k,l,mid);
	build(2*k+1,mid+1,r);
	tree[k]=merge(tree[k*2],tree[k*2+1]);
}
void propagate(int k){
	if(!lazy[k])return;
	lazy[2*k]+=lazy[k];
	lazy[2*k+1]+=lazy[k];
	tree[k].se+=lazy[k];
	lazy[k]=0;
}
void update(int k,int l,int r,ll val, int ul, int ur){
	if(l!=r)propagate(k);
	else{
		tree[k].se+=lazy[k];
		lazy[k]=0;
	}
	if(r<ul||l>ur)return;
	if(r<=ur&&l>=ul){
		lazy[k]+=val;
		if(l!=r)propagate(k);
		else{
			tree[k].se+=lazy[k];
			lazy[k]=0;
		}
		return;
	}
	int mid=(r+l)/2;
	update(k*2,l,mid,val,ul,ur);
	update(k*2+1,mid+1,r,val,ul,ur);
	tree[k]=merge(tree[k*2],tree[k*2+1]);
}
int main(){
    ios::sync_with_stdio(false);
	int n;
	cin>>n;
	REP(i,n){
		cin>>dat[i];
	}
	build(1,0,n-1);
	vi res(n);
	REP(i,n){
		propagate(1);
		pll m=tree[1];
		res[m.first]=i+1;
		if(m.first+1<=n-1)update(1,0,n-1,-(i+1),(int)m.first+1,n-1);
		update(1,0,n-1,LLONG_MAX/10,(int)m.first,(int)m.first);
	}
	REP(i,n){
		if(i)cout<<" ";
		cout<<res[i];
	}

    return 0;
}
