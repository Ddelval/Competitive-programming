//  10301
//    main.cpp
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
#define parent(i) sets[i].parent
#define rank(i)   sets[i].rank
#define size(i)   sets[i].size
struct dset{
	int parent;
	int rank;
	int size;
};
vector<dset> sets;

int find(int i){
	while(parent(i)!=parent(parent(i))){
		parent(i)=parent(parent(i));
	}
	return parent(i);
}
void start(int n){
	sets=vector<dset>(n);
	REP(i,n){
		parent(i)=i;
		size(i)=1;
		rank(i)=1;
	}
}
void Union(int x,int y){
	int px=find(x);
	int py=find(y);
	if(px==py)return;
	if(rank(px)>rank(py)){
		parent(py)=parent(px);
		size(px)+=size(py);
	}
	else if(rank(px)<rank(py)){
		parent(px)=parent(py);
		size(py)+=size(px);
	}
	else{
		parent(px)=parent(py);
		size(py)+=size(px);
		rank(py)++;
	}
}
struct ring{
	double x,y;
	double r;
	ring(double a,double b,double c){
		x=a;
		y=b;
		r=c;
	}
};
vector<ring> rings;
double d(double x1,double y1,double x2, double y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
bool intersect(int i,int j){
	double r,R;
	double dd;
	R=max(rings[i].r,rings[j].r);
	r=min(rings[i].r,rings[j].r);
	dd=d(rings[i].x,rings[i].y,rings[j].x,rings[j].y);
	if(dd<=R){
		return (dd+r)>=R;
	}
	else{
		return dd<=R+r;
	}
}
int main(){
	ios::sync_with_stdio(false);
	
	while(true){
		int n;
		cin>>n;
		if(n==-1)break;
		double a,b,c;
		start(n);
		rings.clear();
		for(int i=0;i<n;++i){
			cin>>a>>b>>c;
			rings.pb(ring(a,b,c));
			for(int j=0;j<i;++j){
				if(intersect(i,j)){
					Union(i,j);
				}
			}
		}
		int m=0;
		REP(i,n){
			m=max(m,size(i));
		}
		cout<<"The largest component contains "<<m<<" ring"<<(m!=1? "s.":".")<<"\n";
		
		
		
		
	}
	
	return 0;
}

