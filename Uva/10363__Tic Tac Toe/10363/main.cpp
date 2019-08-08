// UVa Online Judge 10363: Tic Tac Toe
//  10363
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

int grid[3][3];
int win[2]={0,0};
bool check(){
	int h[2]={0,0},v[2]={0,0};
	int d[2]={0,0};
	win[0]=0;
	win[1]=0;
	REP(i,3){
		if(grid[i][0]&&grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]){
			win[grid[i][0]-1]++;
			h[grid[i][0]-1]++;
		}
	}
	REP(i,3){
		if(grid[0][i]&&grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]){
			win[grid[0][i]-1]++;
			v[grid[0][i]-1]++;
		}
	}
	if(grid[0][0]&&grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2])d[grid[0][0]-1]++;
	if(grid[0][2]&&grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0])d[grid[0][2]-1]++;
	win[0]+=d[0];
	win[1]+=d[1];
	if ((win[0]+win[1])<=1) return true;
	if(!win[0])return h[1]<2&& v[1]<2;
	if(!win[1])return h[0]<2&& v[0]<2;
	return false;
}

int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	REP(z,q){
		char c;
		int counter[3]={0,0,0};
		REP(i,3){
			REP(j,3){
				cin>>c;
				if(c=='.')grid[i][j]=0;
				else if (c=='X')grid[i][j]=1;
				else grid[i][j]=2;
				counter[grid[i][j]]++;
			}
			
		}
		if(!check()){
			cout<<"no";
		}
		else if(!((!win[0]&&counter[1]-counter[2]==0)||(counter[1]-counter[2]==1&&!win[1]))){
			cout<<"no";
		}
		else{
			cout<<"yes";
		}
		cout<<"\n";
	}

    return 0;
}

