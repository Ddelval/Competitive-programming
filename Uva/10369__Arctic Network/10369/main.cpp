//  10369
//	main.cpp
//  Created by David del Val on 02/08/2019
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
int s,p;
int nsets;
vector<pii> posts;
vector<pair<double,pii>> edges;
double d(pii a,pii b){
	return sqrt(pow(a.fi-b.fi,2)+pow(a.se-b.se,2));
}
struct pset{
	int parent,rank;
};
vector<pset> sets;
int find(int i){
	while(sets[i].parent!=sets[sets[i].parent].parent){
		sets[i].parent=sets[sets[i].parent].parent;
	}
	return sets[i].parent;
}
void Union(int x,int y){
	int px=find(x);
	int py=find(y);
	if(px==py)return;
	nsets--;
	if(sets[px].rank>sets[py].rank){
		sets[py].parent=sets[px].parent;
	}
	else if(sets[px].rank<sets[py].rank){
		sets[px].parent=sets[py].parent;
	}
	else{
		sets[px].parent=sets[py].parent;
		sets[py].rank++;
	}
}
void start(){
	sets=vector<pset>(p);
	nsets=p;
	REP(i,p){
		sets[i].parent=i;
		sets[i].rank=1;
	}
}
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	REP(z,q){
		cin>>s>>p;
		int a,b;
		posts=vector<pii>(p);
		start();
		REP(i,p){
			cin>>a>>b;
			posts[i]=mp(a,b);
		}
		edges=vector<pair<double,pii>>(p*p/2);
		REP(i,p){
			REP(j,i){
				edges.pb(mp(d(posts[i],posts[j]),mp(i,j)));
			}
		}
		sort(edges.begin(),edges.end());
		for(auto e:edges){
			Union(e.se.fi, e.se.se);
			if(nsets<=s){
				printf("%.2lf\n",e.fi);
				break;
			}
		}
	}

    return 0;
}

