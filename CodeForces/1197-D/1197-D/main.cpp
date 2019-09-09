//  1197-D
//	main.cpp
//  Created by David del Val on 18/08/2019
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
const int N=int(3e5)+99;

int a[N];
ll bst[N];
ll psum[N]; //Partial sum

ll sum(int l,int r){
	l=max(l,0);
	return psum[r]-(l==0? 0:psum[l-1]);
}

int main(){
    ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	REP(i, n){
		cin>>a[i];
		psum[i]=a[i]+(i==0? 0:psum[i-1]);
		
	}
	ll res=0;
	for(int len=1;len<=m&&len<=n;++len){
		res=max(res,sum(0,len-1)-k);
	}
	
	for(int i=0;i<n;++i){
		if(i+1>=m){
			ll nbst=sum(i-m+1,i)-k;
			if(i-m>=0)nbst+=bst[i-m];
			bst[i]=max(bst[i],+nbst);
		}
		
	}
	for(int i=0;i<n;++i){
		for(int len=0;len<m&&i+len<n;++len){
			res=max(res,bst[i]+sum(i+1,i+len)-k*(len>0));
		}
	}
	cout<<res<<"\n";
	

    return 0;
}


