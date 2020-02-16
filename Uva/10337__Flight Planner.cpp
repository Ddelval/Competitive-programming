// UVa Online Judge 10337: Flight Planner
//  10337
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
int w[10005][9];
int DP[10005][9][3];
int n;
int solve(int cpos, int order, int ch){
	int h;
	int cost;
	if(ch<0||ch>9)return INT_MAX/10;
	if(cpos==n-1&&((ch==0&&order==0)||(ch==1&&order==-1))){
		if(order==-1)return 20-w[cpos][ch];
		if(order==0) return 30-w[cpos][ch];
		else return 60-w[cpos][ch];
	}
	if(cpos==n-1) return INT_MAX/10;
	
	if(DP[cpos][ch][order+1]!=-1)return DP[cpos][ch][order+1];
	if(order==-1){
		h=ch-1;
		cost=20-w[cpos][ch];
	}
	else if(order==0){
		h=ch;
		cost=30-w[cpos][ch];
	}
	else{
		h=ch+1;
		cost=60-w[cpos][ch];
	}
	int mi=INT_MAX;
	for(int i=-1;i<=1;++i){
		mi=min(mi,solve(cpos+1,i,h));
	}
	//cout<<cpos<<" -> "<<ch<<" -> "<<order<<":"<<cost+mi<<"\n";
	return DP[cpos][ch][order+1]=cost+mi;
}

int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		cin>>n;
		n/=100;
		REP(i,n+1)REP(j,9)REP(k,3)DP[i][j][k]=-1;
		REP(i,10)REP(j,n){
			cin>>w[j][9-i];
		}
		cout<<min(solve(0,-1,0),min(solve(0,0,0),solve(0,1,0)))<<"\n\n";
	}

    return 0;
}


