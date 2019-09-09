// UVa Online Judge 10051: Tower of Cubes
//  10051
//	main.cpp
//  Created by David del Val on 14/08/2019
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

struct cube{
	set<int> col;
	map<int,vector<pii>> con;
	vi raw;
	cube(vi s){
		for(int i:s)col.insert(i);
		vector<pii> ab;
		for(int a:s)con[a]=ab;
		REP(i,3){
			con[s[i*2]].push_back(mp(s[i*2+1],i*2+1));
			con[s[i*2+1]].push_back(mp(s[i*2],i*2));
		}
		raw=s;
	}
};

vector<pii> LIS(vector<cube>&vc){
	int n=(int)vc.size();
	
	vector<vector<int>> M(n+1);
	M.assign(n+1, vector<int>(101));
	vector<vector<pii>> P(n);
	P.assign(n, vector<pii>(101));
	vector<vector<int>> O(n);
	O.assign(n, vector<int>(101));
	
	int L=0;
	int x,y;
	for(int i=n-1;i>=0;i--){
		for(int j:vc[i].col){
			auto v=vc[i].con[j];
			for(auto pa:v){
				int &m=M[i][pa.fi];
				
				auto &p=P[i][pa.fi];
				auto &o=O[i][pa.fi];
				if(!m){
					m=1;
					o=pa.se;
				}
				for(int l=n-1;l>i;l--){
					if(M[i][pa.fi]<M[l][j]+1){
						m=M[l][j]+1;
						p=mp(l,j);
						o=pa.se;
						
						if(M[i][pa.fi]>=L){
							L=M[i][pa.fi];
							x=i;
							y=pa.fi;
						}
					}
				}
				
			}
		}
		
	}
	vector<pii>res (L);
	pii st=mp(x,y);
	for(int i=0;i<L;++i){
		res[i]=mp(st.fi,O[st.fi][st.se]);
		st=P[st.fi][st.se];
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	int cas=0;
	while(cin>>n&&n){
		vector<cube> vc;
		REP(i,n){
			vi sid(6);
			REP(j,6){
				cin>>sid[j];
			}
			vc.pb(cube(sid));
		}
		vector<pii> res=LIS(vc);
		if(cas)cout<<"\n";
		cas++;
		cout<<"Case #"<<cas<<"\n"<<res.size()<<"\n";
		for(auto a:res){
			cout<<a.fi+1<<" ";
			switch (a.se) {
				case 0:
					cout<<"front";
					break;
				case 1:
					cout<<"back";
					break;
				case 2:
					cout<<"left";
					break;
				case 3:
					cout<<"right";
					break;
				case 4:
					cout<<"top";
					break;
				case 5:
					cout<<"bottom";
					break;
					
				default:
					break;
			}
			cout<<"\n";
		}
		
	}
	
	return 0;
}

