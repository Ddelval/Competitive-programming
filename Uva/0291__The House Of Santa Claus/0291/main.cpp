//  0291
//	main.cpp
//  Created by David del Val on 01/08/2019
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

struct edge{
	int a,b;
	bool taken;
	edge(int a1,int b1){
		a=a1; b=b1;
		taken =false;
	}
};
vector<edge> v;
int out[9];
void explore(int a,int taken){
	if(taken==8){
		string s="";
		for(int i=0;i<9;++i){
			s+=to_string(out[i]);
		}
		cout<<s<<"\n";
	}
	for(int i=0;i<v.size();++i){
		if(v[i].a==a||v[i].b==a){
			if(!v[i].taken){
				v[i].taken=true;
				int aux= (v[i].a==a)? v[i].b:v[i].a;
				out[taken+1]=aux;
				explore(aux, taken+1);
				v[i].taken=false;
			}
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
	
	edge a=edge(1,2);
	v.pb(a);
	a=edge(1,3);
	v.pb(a);
	a=edge(1,5);
	v.pb(a);
	a=edge(2,3);
	v.pb(a);
	a=edge(2,5);
	v.pb(a);
	a=edge(3,4);
	v.pb(a);
	a=edge(3,5);
	v.pb(a);
	a=edge(4,5);
	v.pb(a);
	out[0]=1;
	explore(1,0);
    return 0;
}

