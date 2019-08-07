// UVa Online Judge 10901: Ferry_Loading_III
//  10901
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
queue<pii> q[2];
int n,t;
vector<int> res;
void simulate(){
	int cpos=0;
	int ct=0;
	while(!q[0].empty()||!q[1].empty()){
		if(q[cpos].empty()){
			cpos=!cpos;
			ct=max(q[cpos].front().fi+t,ct+t);
			continue;
		}
		if(q[cpos].front().fi<=ct){
			ct+=t;
			REP(i,n){
				if(q[cpos].empty()||q[cpos].front().fi>ct-t)break;
				res[q[cpos].front().se]=ct;
				q[cpos].pop();
			}
			cpos=!cpos;
		}
		else{
			if(q[!cpos].empty()||q[cpos].front().fi<=q[!cpos].front().fi){
				ct=q[cpos].front().fi;
			}
			else{
				cpos=!cpos;
				ct=max(q[cpos].front().fi+t,ct+t);
			}
		}
	}
	
}

int main(){
    ios::sync_with_stdio(false);
	int qu;
	cin>>qu;
	REP(z,qu){
		int m;
		cin>>n>>t>>m;
		res=vi(m);
		q[0]=queue<pii>();
		q[1]=queue<pii>();
		int a;string s;
		REP(i,m){
			cin>>a>>s;
			if(s=="left") q[0].push(mp(a,i));
			else q[1].push(mp(a,i));
		}
		simulate();
		REP(i,m){
			cout<<res[i]<<"\n";
		}
		if(z!=qu-1)cout<<"\n";
	}

    return 0;
}

