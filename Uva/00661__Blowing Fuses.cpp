// UVa Online Judge 661: Blowing Fuses
//  0661
//	main.cpp
//  Created by David del Val on 07/08/2019
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

int cost[20];
int on[20];

int main(){
    ios::sync_with_stdio(false);
	int m,n,c;
	int index=1;
	while(cin>>n>>m>>c&&n&&m&&c){
		REP(i,20)on[i]=0;
		REP(i,n){
			cin>>cost[i];
		}
		int a;
		int ccost=0;
		int ma=0;
		REP(i,m){
			cin>>a;
			a--;
			on[a]=!on[a];
			ccost+=(on[a])? cost[a]:(-1*cost[a]);
			ma=max(ma,ccost);
		}
		
		cout<<"Sequence "<<index<<"\n";
		index++;
		if(ma>c)cout<<"Fuse was blown.\n";
		else cout<<"Fuse was not blown.\nMaximal power consumption was "<<ma<<" amperes.\n";
		cout<<"\n";
		
	}

    return 0;
}

