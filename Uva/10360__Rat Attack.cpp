// UVa Online Judge 10360: Rat Attack
//  10360
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

int d;
int grid[1025][1025];
void fill(int x,int y,int inc){
	int lim1,lim2;
	lim1=min(x+d,1024);
	lim2=min(y+d,1024);
	for(int i=max(0,x-d);i<=lim1;++i){
		for(int j=max(0,y-d);j<=lim2;++j){
			grid[i][j]+=inc;
			
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	for(int z=0;z<q;++z){
		int n;
		for(int i=0;i<1025;++i){
			for(int j=0;j<1025;++j){
				grid[i][j]=0;
			}
		}
		cin>>d>>n;
		int x,y,c;
		REP(i,n){
			cin>>x>>y>>c;
			fill(x,y,c);
		}
		int ma=-1;
		int x0,y0;
		for(int i=0;i<1025;++i){
			for(int j=0;j<1025;++j){
				if(grid[i][j]>ma){
					ma=grid[i][j];
					x0=i;
					y0=j;
				}
			}
		}
		cout<<x0<<" "<<y0<<" "<<ma<<"\n";
		
		
	}

    return 0;
}

