// UVa Online Judge 507: Jill Rides Again
//  0507
//	main.cpp
//  Created by David del Val on 16/08/2019
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


int main(){
    ios::sync_with_stdio(false);
	int b;
	cin>>b;
	REP(z,b){
		int s;
		cin>>s;
		vi edges(s);
		REP(i,s-1)cin>>edges[i];
		int psum=0, b_in=-1, e_in=0, ma=INT_MIN, e=0,b=0;
		for(e_in=0;e_in<s-1;++e_in){
			psum+=edges[e_in];
			if(psum>ma){
				ma=psum;
				e=e_in;
				b=b_in;
			}
			else if(psum==ma){
				if(e-b<e_in-b_in){
					ma=psum;
					e=e_in;
					b=b_in;
				}
			}
			if(psum<0){
				psum=0;
				b_in=e_in;
			}
		}
		if(psum>ma){
			ma=psum;
			e=e_in;
			b=b_in;
		}
		if(ma>0)cout<<"The nicest part of route "<<z+1<<" is between stops "<<b+2<<" and "<<e+2<<"\n";
		else cout<<"Route "<<z+1<<" has no nice parts\n";
		
		
		
	}

    return 0;
}


