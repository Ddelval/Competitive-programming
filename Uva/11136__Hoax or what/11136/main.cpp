// UVa Online Judge 11136: Hoax_or_what
//  11136
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


int main(){
    ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n){
		int nn;
		int low_accum=0,high_accum=0;
		map<int,int> low,high;
		int low_c=0,high_c=0;
		int a;
		ll sum=0;
		REP(i,n){
			cin>>nn;
			REP(j,nn){
				cin>>a;
				if(low_c<=(n-i)){
					low[a]++;
					low_c++;
				}
				else{
					auto it=low.end();
					it--;
					if(a<it->fi){
						low_accum++;
						if(it->se<=low_accum){
							low.erase(it);
							low_accum=0;
						}
						low[a]++;
					}
				}
				if(high_c<=(n-i)){
					high[a]++;
					high_c++;
				}
				else{
					auto it=high.begin();
					if(a>it->fi){
						high_accum++;
						if(it->se<=high_accum){
							high.erase(it);
							high_accum=0;
						}
						high[a]++;
					}
				}
			}
			auto it=high.end();
			it--;
			auto it2=low.begin();
			sum+=it->fi-it2->fi;
			
			auto it_1=low.find(it->fi);
			if(it_1!=low.end()){
				if(it_1->se==1){
					low.erase(it_1);
				}
				else{
					it_1->se--;
				}
				low_c--;
			}
			
			if(it->se==1){
				high.erase(it);
			}
			else it->se--;
			high_c--;
			
			
			auto it_2=high.find(it2->fi);
			if(it_2!=high.end()){
				if(it_2->se==1){
					high.erase(it_2);
				}
				else it_2->se--;
				high_c--;
			}
			
			
			if(it2->se==1){
				low.erase(it2);
			}
			else it2->se--;
			low_c--;
		}
		cout<<sum<<"\n";
	}

    return 0;
}

