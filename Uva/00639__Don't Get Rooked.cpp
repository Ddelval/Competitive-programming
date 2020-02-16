// UVa Online Judge 639: Don't Get Rooked
//  0639
//	main.cpp
//  Created by David del Val on 08/08/2019
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
int n;
int board[4][4];
void fill(int i,int nq){
	int x=i/n;
	int y=i%n;
	for(int j=x;j<n;++j){
		if(board[j][y]==-1)break;
		if(!board[j][y])board[j][y]=nq;
	}
	for(int j=y;j<n;++j){
		if(board[x][j]==-1)break;
		if(!board[x][j])board[x][j]=nq;
	}
	for(int j=x-1;j>=0;--j){
		if(board[j][y]==-1)break;
		if(!board[j][y])board[j][y]=nq;
	}
	for(int j=y-1;j>=0;--j){
		if(board[x][j]==-1)break;
		if(!board[x][j])board[x][j]=nq;
	}
}
void unfill(int i,int nq){
	int x=i/n;
	int y=i%n;
	for(int j=x;j<n;++j){
		if(board[j][y]==-1)break;
		if(board[j][y]==nq)board[j][y]=0;
	}
	for(int j=y;j<n;++j){
		if(board[x][j]==-1)break;
		if(board[x][j]==nq)board[x][j]=0;
	}
	for(int j=x-1;j>=0;--j){
		if(board[j][y]==-1)break;
		if(board[j][y]==nq)board[j][y]=0;
	}
	for(int j=y-1;j>=0;--j){
		if(board[x][j]==-1)break;
		if(board[x][j]==nq)board[x][j]=0;
	}
}
int ma;
void place(int stindex,int nq){
	for(int i=stindex;i<n*n;++i){
		if(!board[i/n][i%n]){
			nq++;
			ma=max(ma,nq);
			fill(i,nq);
			place(i+1, nq);
			unfill(i, nq);
			nq--;
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
	while(cin>>n&&n){
		char c;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>c;
				if(c=='X')board[i][j]=-1;
				else board[i][j]=0;
			}
		}
		ma=0;
		place(0,0);
		cout<<ma<<"\n";
	}

    return 0;
}

