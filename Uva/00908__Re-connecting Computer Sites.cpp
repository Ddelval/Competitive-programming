// UVa Online Judge 908: Re-connecting Computer Sites
//  0908
//	main.cpp
//  Created by David del Val on 06/08/2019
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
const long lim=10000009;

ll n,k,t,m;
int parent[lim],rankr[lim];
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> q;

int find(int i){
	while(parent[i]!=parent[parent[i]]){
		parent[i]=parent[parent[i]];
	}
	return parent[i];
}
void Union(int x, int y){
	x=find(x);
	y=find(y);
	if(rankr[x]>rankr[y]){
		parent[y]=parent[x];
	}
	else if(rankr[y]>rankr[x]){
		parent[x]=parent[y];
	}
	else{
		parent[x]=parent[y];
		rankr[y]++;
	}
}
void start(){
	REP(i,n){
		parent[i]=i;
		rankr[i]=1;
	}
}
ll kruskal(){
	ll finalcost=0;
	for(ll selected=0;selected<n-1;){
	//while(!q.empty()){
		auto n=q.top();q.pop();
		if(find(n.se.fi)!=find(n.se.se)){
			finalcost+=n.fi;
			Union(n.se.fi,n.se.se);
			selected++;
		}
	}
	return finalcost;
	
}
int main(){
    ios::sync_with_stdio(false);
	bool b=false;
	while(cin>>n){
		if(b) cout<<"\n";
		b=true;
		ll inicost=0;
		ll a,c,b;
		q=priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>();
		REP(i,n-1){
			cin>>a>>b>>c;
			a--;
			b--;
			inicost+=c;
		}
		cin>>k;
		REP(i,k){
			cin>>a>>b>>c;
			a--;
			b--;
			q.push(mp(c,mp(a,b)));
		}
		cin>>m;
		REP(i,m){
			cin>>a>>b>>c;
			a--;
			b--;
			q.push(mp(c,mp(a,b)));
		}
		start();
		cout<<inicost<<"\n"<<kruskal()<<"\n";
		
	}

    return 0;
}
