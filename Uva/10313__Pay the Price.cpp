// UVa Online Judge 10313: Pay the Price
//  10313
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
const long lim=301;
ll c1 [lim][lim];

void fill(){
	for(int coin=1;coin<=300;++coin){
		c1[coin][1]=1;
		for(int i=coin+1;i<=300;++i){
			for(int j=1;j<=300;++j){
				c1[i][j]+=c1[i-coin][j-1];
			}
			
		}
	}
	
	
}
void solve0(int a){
	if(a==0){
		cout<<"1\n";return;
	}
	ll counter=0;
	for(int i=1;i<=300;++i)counter+=c1[a][i];
	cout<<counter<<"\n";
}
void solve1(int a,int b){
	b=min(b,300);
	if(a==0){
		cout<<"1\n";return;
	}
	ll counter=0;
	for(int i=1;i<=b;++i)counter+=c1[a][i];
	cout<<counter<<"\n";
}

void solve2(int a,int b,int c){
	b=min(b,300);
	c=min(c,300);
	if(a==0&&b==0){
		cout<<"1\n";return;
	}
	ll counter=0;
	for(int i=b;i<=c;++i)counter+=c1[a][i];
	cout<<counter<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
	fill();
	int a,b,c;
	while(cin>>a){
		string s;
		getline(cin,s);
		try {
			size_t aa;
			b=stoi(s,&aa,10);
			s=s.substr(aa);
			try{
				c=stoi(s);
				solve2(a,b,c);
			}
			catch(exception e ){
				solve1(a,b);
			}
			
		} catch (exception e) {
			solve0(a);
		}
	}
	

    return 0;
}


