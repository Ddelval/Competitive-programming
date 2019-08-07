// UVa Online Judge 11495: Bubbles and Buckets
//  11495
//	main.cpp
//  Created by David del Val on 06/08/2019
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
typedef vector<int> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll counter;
void merge(vll&st){
	if(st.size()==1)return;
	int mid=(int)st.size()/2;
	vll v1,v2;
	v1.reserve(mid);
	v1.reserve(st.size()-mid);
	REP(i,mid) v1.pb(st[i]);
	REPO(i,mid,st.size())v2.pb(st[i]);
	merge(v1);
	merge(v2);
	
	int index,i,j;
	index=i=j=0;
	while(i<v1.size()||j<v2.size()){
		while(i<v1.size()&&(v1[i]<=v2[j]||j==v2.size())){
			st[index]=v1[i];
			index++;
			i++;
		}
		while(j<v2.size()&&(v2[j]<v1[i]||i==v1.size())){
			st[index]=v2[j];
			index++;
			j++;
			counter+=v1.size()-i;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n){
		vll v;
		int a;
		v.reserve(n);
		REP(i,n){
			cin>>a;
			v.pb(a);
		}
		counter=0;
		merge(v);
		cout<<((counter%2)? "Marcelo":"Carlos")<<"\n";
	}
	
	return 0;
}

