// UVa Online Judge 10306: e-Coins
//  10306
//	main.cpp
//  Created by David del Val on 15/08/2019
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

int getS2(pii a,pii b){
	return (a.fi+b.fi)*(a.fi+b.fi)+(a.se+b.se)*(a.se+b.se);
}
int DP[301][301];
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		int m,s;
		cin>>m>>s;
		vector<pii>coins(m);
		REP(i,m)cin>>coins[i].fi>>coins[i].se;
		REP(i,300)REP(j,300)DP[i][j]=0;
		for(auto a:coins){
			DP[a.fi][a.se]=1;
			REP(i,s+1){
				REP(j,s+1){
					if(i-a.fi>=0&&j-a.se>=0){
						int i0=i-a.fi;
						int i1=j-a.se;
						if(DP[i0][i1]&&(!DP[i][j]||DP[i0][i1]+1<DP[i][j])){
							DP[i][j]=DP[i0][i1]+1;
						}
					}
				}
			}
		}
		int mi=INT_MAX/2;
		for(int x=0;x<=s;x++){
			double d=sqrt(s*s-x*x);
			if(d==ceil(d)&&DP[x][(int)d]){
				mi=min(mi,DP[x][(int)d]);
			}
		}
		if(mi==INT_MAX/2)cout<<"not possible\n";
		else cout<<mi<<"\n";
	}

    return 0;
}


