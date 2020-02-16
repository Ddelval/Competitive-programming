// UVa Online Judge 222: Budget Travel
//  0222
//	main.cpp
//  Created by David del Val on 19/08/2019
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
typedef pair<double, double> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

vii stations;
double destination;
double range,mpg,capacity;
int solve(double cini,int gasindex){
	if(gasindex==stations.size()){
		if(destination-cini>range)return INT_MAX;
		return 0;
	}
	if(stations[gasindex].fi-cini>range)return INT_MAX;
	double expended=(stations[gasindex].fi-cini)/mpg;
	bool canstop=true;
	if(expended<capacity/2){
		if(gasindex!=sz(stations)-1){
			if(stations[gasindex+1].fi-cini<=range)canstop=false;
		}
		else{
			if(destination-cini<=range)canstop=false;
		}
	}
	
	if(canstop){
		double cost=expended*stations[gasindex].se;
		cost=round(cost);
		return min((int)cost+200+solve(stations[gasindex].fi,gasindex+1),solve(cini,gasindex+1));
	}
	else return solve(cini,gasindex+1);
}

int main(){
    ios::sync_with_stdio(false);
	int counter=0;
	while(cin>>destination&&destination>=0){
		double icost;
		cin>>capacity>>mpg>>icost;
		range=capacity*mpg;
		int n;
		cin>>n;
		double a,b;
		stations.clear();
		REP(i,n){
			cin>>a>>b;
			stations.pb(mp(a,b));
		}
		double res=(solve(0, 0)+icost*100)/100;
		counter++;
		printf("Data Set #%d\nminimum cost = $%.2lf\n",counter,res);
	}

    return 0;
}


