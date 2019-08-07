// UVa Online Judge 739: Soundex Indexing
//  0739
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

char dic[200];

void add(int code, char letter){
	dic[letter]=code+'0';
}

int main(){
    ios::sync_with_stdio(false);
	
	add(1,'B'); add(1,'P'); add(1,'F'); add(1,'V');
	add(2,'C'); add(2,'S'); add(2,'K'); add(2,'G'); add(2,'J'); add(2,'Q'); add(2,'X'); add(2,'Z');
	add(3,'D'); add(3,'T');
	add(4,'L');
	add(5,'M'); add(5,'N');
	add(6,'R');
	
	REP(i, 9)cout<<" ";
	cout<<"NAME";
	REP(i, 21)cout<<" ";
	cout<<"SOUNDEX CODE\n";
	string s;
	
	while(cin>>s){
		string a="";
		a+=s[0];
		int index=1;
		for(int i=1;i<s.length();++i){
			if(dic[s[i]]&&dic[s[i]]!=dic[s[i-1]]){
				a+=dic[s[i]];
				index++;
				if(index==4)break;
			}
		}
		while(index<4){
			a+='0';
			index++;
		}
		REP(i, 9)cout<<" ";
		cout<<s;
		REP(i,35-10-(int)s.length())cout<<" ";
		cout<<a<<"\n";
	}
	REP(i, 19)cout<<" ";
	cout<<"END OF OUTPUT\n";
    return 0;
}

