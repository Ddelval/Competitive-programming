// UVa Online Judge 10891: Game of Sum
//  10891
//	main.cpp
//  Created by David del Val on 21/08/2019
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
const int lim=100;
ll DP[101][101][2];
ll sum[101];
ll arr[101];
ll su(int a, int b){
	if(a>b)swap(a,b);
	if(a)return sum[b]-sum[a-1];
	else return sum[b];
}
ll solve(int l,int r, int turn){
	
	if(l>r)return 0;
	if(l==r){
		if(!turn)return arr[r];
		else return -arr[r];
	}
	if(DP[l][r][turn]!=LLONG_MAX/3)return DP[l][r][turn];
	else{
		if(turn){
			ll mi=LLONG_MAX/3;
			for(int i=r;i>=l;--i){
				mi=min(mi,-su(r,i)+solve(l,i-1,!turn));
			}
			for(int i=l;i<=r;++i){
				mi=min(mi,-su(i,l)+solve(i+1,r,!turn));
			}
			return DP[l][r][turn]=mi;
		}
		else{
			ll mi=LLONG_MIN/3;
			for(int i=r;i>=l;--i){
				mi=max(mi,su(r,i)+solve(l,i-1,!turn));
			}
			for(int i=l;i<=r;++i){
				mi=max(mi,su(i,l)+solve(i+1,r,!turn));
			}
			return DP[l][r][turn]=mi;
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n){
		REP(i,n)cin>>arr[i];
		REP(i,n+1)REP(j,n+1)REP(z,2)DP[i][j][z]=LLONG_MAX/3;
		REP(i,n){
			sum[i]=arr[i];
			if(i)sum[i]+=sum[i-1];
		}
		cout<<solve(0,n-1,0)<<"\n";
	}

    return 0;
}


