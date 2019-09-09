//  C
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

bool ady[100][100];
int dist[100][100];
void Washall(int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(ady[i][j])dist[i][j]=1;
			else dist[i][j]=INT_MAX/3;
		}
	}
	for(int z=0;z<n;++z){
		for(int j=0;j<n;++j){
			for(int i=0;i<n;++i){
				if(dist[i][j]>dist[i][z]+dist[z][j]){
					dist[i][j]=dist[i][z]+dist[z][j];
				}
			}
			
		}
	}
	for(int i=0;i<n;++i){
		dist[i][i]=INT_MAX/3;
	}
}
int main(){
    ios::sync_with_stdio(false);
	int n;
	cin>>n;
	char c;
	REP(i,n)REP(j,n){
		cin>>c;
		if(c=='1')ady[i][j]=true;
	
	}
	int m;
	cin>>m;
	vi seq(m);
	vector<bool> rem(m,0);
	REP(i,m)cin>>seq[i];
	REP(i,m)seq[i]--;
	Washall(n);
	int j=1;
	for(int i=0;i<sz(seq)-1;++i){
		if(rem[i])continue;
		while(j-i<2)j++;
		if(j>=sz(seq))break;
		while(dist[seq[i]][seq[j]]==j-i){
			rem[j-1]=true;
			j++;
			if(j>=sz(seq))break;
		}
		
	}
	bool b=false;
	int count=0;
	for(int i=0;i<sz(seq);++i)count+=!rem[i];
	cout<<count<<"\n";
	for(int i=0;i<sz(seq);++i){
		if(!rem[i]){
			if(b)cout<<" ";
			b=true;
			cout<<seq[i]+1;
		}
	}

    return 0;
}


