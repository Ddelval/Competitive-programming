//  10480
//	main.cpp
//  Created by David del Val on 30/08/2019
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
ll graph[51][51];
bool connected[51][51];
bool visited[51];
int parent[51];
int n,src,snk;
bool bfs(){
	memset(visited,0,50);
	queue<int> q;
	q.push(src);
	visited[src]=true;
	while(!q.empty()){
		int a=q.front();q.pop();
		for(int i=0;i<n;++i){
			if(graph[a][i]>0&&!visited[i]){
				visited[i]=true;
				parent[i]=a;
				if(i==snk)return true;
				q.push(i);
			}
		}
	}
	return false;
}
int main(){
    ios::sync_with_stdio(false);
	int m;
	src=1;
	snk=2;
	while(cin>>n>>m&&n&&m){
		n++;
		REP(i,n)REP(j,n)graph[i][j]=0;
		REP(i,n)REP(j,n)connected[i][j]=0;
		ll a,b,w;
		REP(i,m){
			cin>>a>>b>>w;
			graph[a][b]+=w;
			graph[b][a]+=w;
			connected[a][b]=connected[b][a]=true;
		}
		while(bfs()){
			ll m=INT_MAX;
			for(ll p=snk;p!=src;p=parent[p])m=min(m,graph[parent[p]][p]);
			for(ll p=snk;p!=src;p=parent[p]){
				graph[parent[p]][p]-=m;
				graph[p][parent[p]]+=m;
			}
		}
		bfs();
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(connected[i][j]&&visited[i]&&!visited[j]){
					cout<<j<<" "<<i<<"\n";
				}
			}
		}
		cout<<"\n";
		
	}

    return 0;
}
