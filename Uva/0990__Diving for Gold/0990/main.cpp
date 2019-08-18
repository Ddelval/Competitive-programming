// UVa Online Judge 990: Diving for Gold
//  0990
//	main.cpp
//  Created by David del Val on 17/08/2019
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

int DP[31][1001];
pii P[31][1001];
int main(){
    ios::sync_with_stdio(false);
	int t,w,n;
	bool bbb=false;
	while(cin>>t>>w){
		if(bbb)cout<<"\n";
		bbb=true;
		cin>>n;
		vii dat(n);
		REP(i,n){cin>>dat[i].fi>>dat[i].se; dat[i].fi=3*dat[i].fi*w;}
		for(int j=0;j<=t;++j){
			if(dat[0].fi<=j){
				DP[0][j]=dat[0].se;
				P[0][j]=mp(-1,j);
			}
			else{
				DP[0][j]=0;
				P[0][j]=mp(-1,-1);
			}
			
		}
		for(int i=1;i<n;++i){
			for(int j=0;j<=t;++j){
				if(dat[i].fi<=j){
					if(DP[i-1][j-dat[i].fi]+dat[i].se>DP[i-1][j]){
						DP[i][j]=DP[i-1][j-dat[i].fi]+dat[i].se;
						P[i][j]=mp(i-1,j-dat[i].fi);
						continue;
					}
				}
				DP[i][j]=DP[i-1][j];
				P[i][j]=mp(i-1,j);
			}
		}
		cout<<DP[n-1][t]<<"\n";
		vi treass;
		pii back=mp(n-1,t);
		while(P[back.fi][back.se].fi!=-1){
			if(P[back.fi][back.se].se!=back.se)treass.pb(back.fi);
			back=P[back.fi][back.se];
		}
		if(P[back.fi][back.se].se!=-1)treass.pb(back.fi);
		reverse(treass.begin(),treass.end());
		cout<<treass.size()<<"\n";
		for(int a:treass)cout<<(dat[a].fi/3)/w<<" "<<dat[a].se<<"\n";
	}

    return 0;
}


