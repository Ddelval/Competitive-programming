// UVa Online Judge 103: Stacking Boxes
//  0103
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

struct box{
	int index;
	int dim;
	vector<int> siz;
};
bool operator <(box &a,box&b){
	priority_queue<int,vector<int>,greater<int>> pa;
	priority_queue<int,vector<int>,greater<int>> pb;
	for(int i:a.siz)pa.push(i);
	for(int i:b.siz)pb.push(i);
	while(!pa.empty()&&pa.top()<pb.top()){
		pa.pop(); pb.pop();
	}
	return pa.empty();
}
int main(){
    ios::sync_with_stdio(false);
	vector<box> dat;
	int n,dim;
	while(cin>>n>>dim){
		dat.reserve(n);
		dat.clear();
		REP(i,n){
			box a;
			a.index=i;
			a.dim=dim;
			a.siz=vi(dim);
			REP(j,dim){
				cin>>a.siz[j];
			}
			sort(a.siz.begin(),a.siz.end());
			dat.pb(a);
		}
		vector<pii> lis(n);
		sort(dat.begin(),dat.end(),[](box &a,box &b){
			for(int i=0;i<a.dim;++i){
				if(a.siz[i]!=b.siz[i])return a.siz[i]<b.siz[i];
			}
			return true;
		});
		for(int i=0;i<dat.size();++i){
			int ans=1;
			int index=-1;
			for(int j=0;j<i;++j){
				if(dat[j]<dat[i]){
					if(ans<lis[j].fi+1){
						ans=lis[j].fi+1;
						index=j;
					}
				}
			}
			lis[i]=mp(ans,index);
		}
		auto ab=max_element(lis.begin(),lis.end());
		pii a=*ab;
		int siz=a.fi;
		stack<int>history;
		history.push(dat[ab-lis.begin()].index);
		while(a.se!=-1){
			history.push(dat[a.se].index);
			a=lis[a.se];
		}
		cout<<siz<<"\n";
		bool b=false;
		while(!history.empty()){
			if(b)cout<<" ";
			b=true;
			cout<<history.top()+1;
			history.pop();
		}
		cout<<"\n";
		
	}

    return 0;
}

