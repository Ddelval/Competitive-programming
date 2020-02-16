//  D
//	main.cpp
//  Created by David del Val on 11/08/2019
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
pii maxmin[2005];
pii maxminv[2005];
bool board[2005][2005];
int main(){
    ios::sync_with_stdio(false);
	int k,n;
	cin>>n>>k;
	char c;
	int whitelines=0;
	for(int i=0;i<n;++i){
		maxminv[i].se=-1;
		maxminv[i].fi=20005;
	}
	for(int i=0;i<n;++i){
		maxmin[i].se=-1;
		maxmin[i].fi=20005;
		for(int j=0;j<n;++j){
			cin>>c;
			if(c=='W'){
				board[i][j]=false;
			}
			else{
				if(j<maxmin[i].fi)maxmin[i].fi=j;
				if(j>maxmin[i].se)maxmin[i].se=j;
				if(i<maxminv[j].fi)maxminv[j].fi=i;
				if(i>maxminv[j].se)maxminv[j].se=i;
				board[i][j]=true;
			}
		}
		if(maxmin[i].se==-1)whitelines++;
	}
	for(int i=0;i<n;++i){
		if(maxminv[i].se==-1)whitelines++;
	}
	int whiteincrement=0;
	for(int i=k-1;i<n;++i){
		int cw=0;
		for(int j=0;j<k;++j){
			
			if(maxmin[j].se!=-1&&maxmin[j].se<=i&& maxmin[j].fi>=i-k+1)cw++;
			
		}
		int cwv=0;
		for(int m=0;m<k;++m){
			if(maxminv[i-m].se!=-1&&maxminv[i-m].fi>=0&&maxminv[i-m].se<=k-1)cwv++;
		}
		whiteincrement=max(whiteincrement,cw+cwv);
		for(int j=k;j<n;++j){
			
			if(maxmin[j].se!=-1&&maxmin[j].se<=i&& maxmin[j].fi>=i-k+1)cw++;
			
			
			if(maxmin[j-k].se!=-1&&maxmin[j-k].se<=i&& maxmin[j-k].fi>=i-k+1)cw--;
			
			cwv=0;
			for(int m=0;m<k;++m){
				if(maxminv[i-m].se!=-1&&maxminv[i-m].fi>=j-k+1&&maxminv[i-m].se<=j)cwv++;
			}
			whiteincrement=max(whiteincrement,cw+cwv);
		}
	}
	cout<<whiteincrement+whitelines;
	
    return 0;
}

