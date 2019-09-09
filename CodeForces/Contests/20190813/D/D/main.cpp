//  D
//	main.cpp
//  Created by David del Val on 13/08/2019
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
string s,t;
int ma=0;;
int dl[200000],dr[200000];
int findlcs_left(){
	int i_s=0,i_t=0;
	for(i_s=0;i_s<s.length();++i_s){
		if(s[i_s]==t[i_t]){
			dl[i_t]=i_s;
			i_t++;
		}
		if(i_t==t.length())return i_s;
	}
	return 0;
}

int findlcs_right(){
	int i_s=(int)s.length()-1,i_t=(int)t.length()-1;
	for(;i_s>=0;--i_s){
		if(s[i_s]==t[i_t]){
			dr[i_t]=i_s;
			i_t--;
		}
		if(i_t==-1)return i_s;
	}
	return 0;
}

int main(){
    ios::sync_with_stdio(false);
	cin>>s;
	cin>>t;
	findlcs_left();
	findlcs_right();
	for(int i=0;i<(int)t.length()-1;++i){
		ma=max(ma,abs(dr[i+1]-dl[i]-1));
	}
	ma=max(ma,dr[0]);
	t.length();
	ma=max(ma,(int)s.length()-1-dl[(int)t.length()-1]);
	cout<<ma;

    return 0;
}

