// UVa Online Judge 193: Graph Coloring
//  0193
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

bool black[110];
bool fin[110];
vector<vi> adyList;
int solve(int nnode){
	if(nnode==sz(adyList))return 0;
	bool b=false;
	for(int a:adyList[nnode]){
		if(black[a]){
			b=true;
			break;
		}
	}
	if(!b){
		black[nnode]=true;
		int pr=solve(nnode+1);
		black[nnode]=false;
		int p2=solve(nnode+1);
		if(pr>=p2){
			fin[nnode]=true;
			black[nnode]=true;
			pr=solve(nnode+1);
			black[nnode]=false;
			return 1+pr;
		}
		fin[nnode]=false;
		return p2;
	}
	fin[nnode]=false;
	return solve(nnode+1);
}

int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		REP(i,110)black[i]=false;
		REP(i,110)fin[i]=false;
		int n,k;
		cin>>n>>k;
		vi a;
		adyList=vector<vi>(n,a);
		int b1,b2;
		REP(i,k){
			cin>>b1>>b2;
			b1--;
			b2--;
			adyList[b1].pb(b2);
			adyList[b2].pb(b1);
		}
		cout<<solve(0)<<"\n";
		bool b=false;
		for(int i=0;i<100;++i){
			if(fin[i]){
				if(b)cout<<" ";
				cout<<i+1;
				b=1;
			}
		}
		cout<<"\n";
	}

    return 0;
}


