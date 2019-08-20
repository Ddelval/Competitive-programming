// UVa Online Judge 607: Scheduling Lectures
//  0607
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

int n,L,C;
pii DP[1001][501];
void crem(pii &res, int rem){
	if(!rem)return;
	if(rem<=10)res.se+=C;
	else res.se+=(int)pow((rem-10),2);
}
vi lectures;
pii solve(int lindex,int rem){
	if(DP[lindex][rem].fi!=-1)return DP[lindex][rem];
	if(lindex==n){
		pii res=mp(0,0);
		crem(res,rem);
		return res;
	}
	if(lectures[lindex]>rem){
		pii res=solve(lindex+1,L-lectures[lindex]);
		res.fi++;
		crem(res,rem);
		return DP[lindex][rem]=res;
	}
	else{
		pii res1=solve(lindex+1,L-lectures[lindex]);
		res1.fi++;
		crem(res1,rem);
		pii res2=solve(lindex+1,rem-lectures[lindex]);
		if(res1.fi<res2.fi)return DP[lindex][rem]=res1;
		if(res2.fi<res1.fi)return DP[lindex][rem]=res2;
		if(res1.se<res2.se)return DP[lindex][rem]=res1;
		else return DP[lindex][rem]=res2;
	}
}
int main(){
    ios::sync_with_stdio(false);
	int cas=0;
	while(cin>>n&&n){
		REP(i,n+1)REP(j,501)DP[i][j]=mp(-1,-1);
		if(cas)cout<<"\n";
		cin>>L>>C;
		C*=-1;
		lectures=vi(n);
		REP(i,n)cin>>lectures[i];
		pii res=solve(0,L);
		res.fi++;
		cas++;
		cout<<"Case "<<cas<<":\n";
		cout<<"Minimum number of lectures: "<<res.fi<<"\n";
		cout<<"Total dissatisfaction index: "<<res.se<<"\n";
		
	}

    return 0;
}


