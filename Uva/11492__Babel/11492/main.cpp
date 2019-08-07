// UVa Online Judge 11492: Babel
//  11492
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
const long lim=5000;
int m;
// destiny, length, initial
vector<vector<pair<int,pair<int,char>>>> adyList;
map<string,int> languages;
bool explored[lim][27];
int cval[lim][27];
int Dijkstra(){
	REP(i,languages.size())
	REP(i,languages.size()){
		REP(j,27){
			cval[i][j]=INT_MAX;
			explored[i][j]=false;
		}
		
	}
	REP(j,27){
		cval[0][j]=0;
		explored[0][j]=true;
	}
	//weight, lastchar, cnode
	priority_queue<pair<int,pair<char,int>>,vector<pair<int,pair<char,int>>>,greater<pair<int,pair<char,int>>>> pq;
	pq.push({0,{'a',0}});
	while(!pq.empty()){
		auto a=pq.top();
		pq.pop();
		explored[a.se.se][a.se.fi-'a']=true;
		if(a.se.se==1){
			break;
		}
		if(a.fi!=cval[a.se.se][a.se.fi-'a'])continue;
		for(auto b:adyList[a.se.se]){
			if(a.se.se&&b.se.se==a.se.fi)continue;
			if(explored[b.fi][b.se.se-'a'])continue;
			if(cval[a.se.se][a.se.fi-'a']+b.se.fi<cval[b.fi][b.se.se-'a']){
				cval[b.fi][b.se.se-'a']=cval[a.se.se][a.se.fi-'a']+b.se.fi;
				pq.push(mp(cval[b.fi][b.se.se-'a'],mp(b.se.se,b.fi)));
			}
		}
	}
	
	int mi=INT_MAX;
	REP(i,27){
		mi=min(mi,cval[1][i]);
	}
	
	return mi;
}

int main(){
    ios::sync_with_stdio(false);
	while(cin>>m&&m){
		string o,e;
		int index=0;
		cin>>o>>e;
		vector<pair<int,pair<int,char>>> vpc;
		adyList.assign(lim,vpc);
		languages.clear();
		languages[o]=index;
		index++;
		languages[e]=index;
		index++;
		string a,b,c;
		REP(i,m){
			cin>>a>>c>>b;
			index+=languages.insert(mp(a,index)).se;
			index+=languages.insert(mp(c,index)).se;
			int a1=languages[a], a2=languages[c];
			adyList[a1].pb(mp(a2,mp(b.length(),b[0])));
			adyList[a2].pb(mp(a1,mp(b.length(),b[0])));
		}
		int res=Dijkstra();
		if(res==INT_MAX){
			cout<<"impossivel\n";
		}
		else{
			cout<<res<<"\n";
		}
		
	}

    return 0;
}
