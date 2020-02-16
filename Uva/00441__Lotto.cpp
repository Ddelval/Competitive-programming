//  0441
//	main.cpp
//  Created by David del Val on 08/08/2019
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


int main(){
    ios::sync_with_stdio(false);
	int k;
	int index=0;
	while(cin>>k&&k){
		if(index)cout<<"\n";
		index=1;
		vi v(k);
		for(int i=0;i<k;++i)cin>>v[i];
		sort(v.begin(), v.end());
		
		for(int i1=0;i1<v.size()-5;i1++){
			for(int i2=i1+1;i2<v.size()-4;i2++){
				for(int i3=i2+1;i3<v.size()-3;i3++){
					for(int i4=i3+1;i4<v.size()-2;i4++){
						for(int i5=i4+1;i5<v.size()-1;i5++){
							for(int i6=i5+1;i6<v.size()  ;i6++){
								cout<<v[i1]<<" "<<v[i2]<<" "<<v[i3]<<" "<<v[i4]<<" "<<v[i5]<<" "<<v[i6]<<"\n";
							}
						}
					}
				}
			}
		}
	}

    return 0;
}

