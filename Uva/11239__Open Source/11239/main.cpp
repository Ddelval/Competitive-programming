// UVa Online Judge 11239: Open Source
//  11239
//	main.cpp
//  Created by David del Val on 04/08/2019
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

bool comp(pair<int,string>& a,pair<int,string>&b){
	if(a.fi<b.fi)return !true;
	if(a.fi>b.fi)return !false;
	if(a.se>b.se)return !true;
	if(a.se<b.se)return !false;
	
	
	return false;
}
int main(){
    ios::sync_with_stdio(false);
	string s="1";
	while(s[0]!='0'){
		getline(cin,s);
		vector<pair<string,set<string>>> m;
		set<string> all,nocount;
		while(s[0]!='1'&&s[0]!='0'){
			set<string> vec;
			string a;
			while(getline(cin,a)&&(a[0]<'A'||a[0]>'Z')&&a[0]!='1'&&a[0]!='0'){
				vec.insert(a);
				if(all.count(a))nocount.insert(a);
			}
			for(auto a:vec)all.insert(a);
			m.pb(mp(s,vec));
			s=a;
		}
		vector<pair<int,string>> v;
		for(auto a:m){
			int counter=0;
			for(auto b:a.se){
				counter+=!nocount.count(b);
			}
			v.pb(mp(counter,a.fi));
		}
		sort(v.begin(),v.end(),comp);
		for(auto a:v)cout<<a.se<<" "<<a.fi<<"\n";
	}
	

    return 0;
}

