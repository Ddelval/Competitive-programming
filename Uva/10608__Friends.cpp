// UVa Online Judge 10608: Friends
//  10608
//	main.cpp
//  Created by David del Val on 05/08/2019
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
#define LIM 30009
int parent[LIM], sizee[LIM],rankk[LIM];

int find(int i){
	while(parent[i]!=parent[parent[i]]){
		parent[i]=parent[parent[i]];
	}
	return parent[i];
}
void Union(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rankk[x]>rankk[y]){
		sizee[x]+=sizee[y];
		parent[y]=parent[x];
	}
	else if(rankk[x]<rankk[y]){
		sizee[y]+=sizee[x];
		parent[x]=parent[y];
	}
	else{
		rankk[x]++;
		sizee[x]+=sizee[y];
		parent[y]=parent[x];
	}
}

void start(int n){
	REP(i, n){
		parent[i]=i;
		sizee[i]=1;
	}
}

int main(){
    ios::sync_with_stdio(false);
	int n,m;
	int cas=0;
	int q;
	cin>>q;
	REP(z,q){
		cin>>n>>m;
		cas++;
		start(n);
		int a,b;
		REP(j,m){
			cin>>a>>b;
			a--;b--;
			Union(a,b);
		}
		int ma=INT_MIN;
		REP(i,n)ma=max(ma,sizee[i]);
		cout<<ma<<"\n";
	}

    return 0;
}

