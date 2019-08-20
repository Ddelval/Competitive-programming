// UVa Online Judge 116: Unidirectional TSP
//  0116
//	main.cpp
//  Created by David del Val on 20/08/2019
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
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
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

int board[10][100];
int DP[10][100];
int m,n;
int explore(int x,int y){
	if(x==n)return 0;
	if(y<0)y+=m;
	y%=m;
	if(DP[y][x]!=INT_MAX)return DP[y][x];
	return DP[y][x]=board[y][x]+min(explore(x+1,y),min(explore(x+1,y-1),explore(x+1,y+1)));
}
int mod(int y){
	if(y<0)y+=m;
	y%=m;
	return y;
}
int main(){
    ios::sync_with_stdio(false);
	while(cin>>m>>n){
		REP(i,m)REP(j,n){
			cin>>board[i][j];
			DP[i][j]=INT_MAX;
		}
		int mi=INT_MAX;
		int row;
		REP(i,m){
			if(explore(0,i)<mi){
				mi=explore(0, i);
				row=i;
			}
		}
		int x,y;
		x=0; y=row;
		bool b=false;
		while(x<(n-1)){
			if(b)cout<<" ";
			b=true;
			cout<<y+1;
			vector<pair<pii,pii>> so;
			so.pb(mp(mp(DP[y][x+1],y),mp(y,x+1)));
			so.pb(mp(mp(DP[mod(y+1)][x+1],mod(y+1)),mp(mod(y+1),x+1)));
			so.pb(mp(mp(DP[mod(y-1)][x+1],mod(y-1)),mp(mod(y-1),x+1)));
			sort(all(so));
			x=so[0].se.se;
			y=so[0].se.fi;
		}
		if(b)cout<<" ";
		b=true;
		cout<<y+1<<"\n";
		cout<<mi<<"\n";
	}

    return 0;
}


