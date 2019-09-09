//  1202-B
//	main.cpp
//  Created by David del Val on 09/08/2019
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

int DP[10][10][10];
bool visited[10];
int dfs(int x, int y,int n){
	REP(i,10)visited[i]=0;
	
	queue<pii>q;
	q.push(mp(0,0));
	bool st=false;
	while(!q.empty()){
		auto a=q.front(); q.pop();
		if(st&&a.fi==n){
			DP[y][x][n]=a.se;
			return DP[x][y][n]=a.se;
		}
		if(visited[a.fi])continue;
		visited[a.fi]=true;
		
		q.push(mp((a.fi+x)%10,a.se+1));
		q.push(mp((a.fi+y)%10,a.se+1));
		
		
		st=true;
	}
	DP[y][x][n]=-1;
	return DP[x][y][n]=-1;
}

int mod(char a,char b){
	if(b-a<0)return b-a+10;
	else return b-a;
}
int main(){
    ios::sync_with_stdio(false);
	string str;
	REP(i,10){
		REP(j,10){
			REP(z,10){
				DP[i][j][z]=-5;
			}
		}
	}
	REP(i,10){
		REPO(j,i,10){
			REP(z,10){
				DP[i][j][z]=dfs(i,j,z);
			}
		}
	}
	while(cin>>str){
		vector<int> v;
		v.reserve(str.length());
		for(int i=1;i<str.length();++i){
			v.pb(mod(str[i-1],str[i]));
		}
		for(int a=0;a<10;++a){
			for(int b=0;b<10;++b){
				ll sum=0;
				for(int i:v){
					int ab= DP[a][b][i];
					if(ab==-1){
						sum=INT_MIN;
						break;
					}
					sum+=ab-1;
				}
				if(b)cout<<" ";
				if(sum<0)cout<<"-1";
				else cout<<sum;
			}
			cout<<"\n";
		}
	}

    return 0;
}

