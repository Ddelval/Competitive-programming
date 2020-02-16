//  1195-E
//	main.cpp
//  Created by David del Val on 29/08/2019
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
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

ll mat[3005][3005];
ll comp[3005][3005];
int main(){
    ios::sync_with_stdio(false);
	ll g,x,y,ic;
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	cin>>g>>x>>y>>ic;
	REP(i,n)REP(j,m){
		mat[i][j]=g; 
		g=(g*x+y)%ic;
	}
	//Go through each row
	REP(i,n){
		deque<pii> dq;
		for(int j=0;j<b;++j){
			while(!dq.empty()&&dq.back().fi>mat[i][j])dq.pop_back();
			dq.pb(mp(mat[i][j],j));
		}
		comp[i][b-1]=dq.front().fi;
		for(int j=b;j<m;++j){
			while(!dq.empty()&&dq.front().se<=j-b)dq.pop_front();
			while(!dq.empty()&&dq.back().fi>mat[i][j])dq.pop_back();
			dq.pb(mp(mat[i][j],j));
			comp[i][j]=dq.front().fi;
		}
	}
	//Go through each column
	/*for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			printf("%10lld ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n----------");
	printf("\n");
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			printf("%10lld ",comp[i][j]);
		}
		printf("\n");
	}*/
	ll sum=0;
	for(int j=b-1;j<m;++j){
		deque<pii> dq;
		for(int i=0;i<a;++i){
			while(!dq.empty()&&dq.back().fi>comp[i][j])dq.pop_back();
			dq.pb(mp(comp[i][j],i));
		}
		sum+=dq.front().fi;
		for(int i=a;i<n;++i){
			while(!dq.empty()&&dq.front().se<=i-a)dq.pop_front();
			while(!dq.empty()&&dq.back().fi>comp[i][j])dq.pop_back();
			dq.pb(mp(comp[i][j],i));
			sum+=dq.front().fi;
		}
	}
	cout<<sum;

    return 0;
}
