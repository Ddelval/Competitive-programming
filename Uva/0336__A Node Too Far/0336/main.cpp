// UVa Online Judge 336: A_Node_Too_Far
//  0336
//	main.cpp
//  Created by David del Val on 04/08/2019
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
bool explored[30];
int dist;
int st;
vector<vector<int>> adyList;

void BFS(){
	queue<pii> q;
	q.push(mp(st,0));
	while (!q.empty()) {
		auto a=q.front();
		q.pop();
		explored[a.fi]=1;
		if(a.se<dist){
			for(auto b:adyList[a.fi]){
				if(!explored[b]){
					q.push(mp(b,a.se+1));
				}
			}
		}
	}
	
	
}
int main(){
    ios::sync_with_stdio(false);
	int n;
	int cas=0;
	map<int,int> tr;
	while(cin>>n&&n){
		tr.clear();
		
		adyList.clear();
		vi aaaa;
		adyList.assign(30, aaaa);
		int index=0;
		REP(i,n){
			int a,b;
			cin>>a; cin>>b;
			if(!tr.count(a)){
				tr[a]=index;
				index++;
			}
			if(!tr.count(b)){
				tr[b]=index;
				index++;
			}
			adyList[tr[a]].pb(tr[b]);
			adyList[tr[b]].pb(tr[a]);
		}
		int a,b;
		
		while(cin>>a>>b&&(a||b)){
			cas++;
			int count=0;
			if(tr.count(a)){
				st=tr[a];
				dist=b;
				REP(i,30) explored[i]=false;
				BFS();
				REP(i,30) if(!explored[i]) count++;
			}
			else{
				count=30;
			}
			cout<<"Case "<<cas<<": "<<count-(30-tr.size());
			cout<<" nodes not reachable from node "<<a;
			cout<<" with TTL = "<<b<<".\n";
		}
	}

    return 0;
}

