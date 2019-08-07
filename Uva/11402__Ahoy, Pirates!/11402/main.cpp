// UVa Online Judge 11402: Ahoy,_Pirates!
//  11402
//	main.cpp
//  Created by David del Val on 05/08/2019
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

vi tree;
vector<char> lazy;
string s;
void build (int k,int l,int r){
	if(l==r){
		tree[k]=s[l]-'0';
		return;
	}
	int mid=(r+l)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k]=tree[k<<1]+tree[k<<1|1];
}
void propagate (int n,char code){
	if(n>=4*s.length())return;
	if(lazy[n]){
		if(code!='I'){
			lazy[n]=code;
		}
		else{
			if(lazy[n]=='E')lazy[n]='F';
			else if(lazy[n]=='F') lazy[n]='E';
			else lazy[n]=0;
		}
	}
	else lazy[n]=code;
	
}
void laz(int k,int l,int r){
	if(k>=4*s.length())return;
	if(lazy[k]){
		char code=lazy[k];
		if(code=='F'){
			tree[k]=r-l+1;
			
		}
		else if(code=='E'){
			tree[k]=0;
			
		}
		else{
			tree[k]=r-l+1-tree[k];
			
		}
		lazy[k]=0;
		propagate(k<<1, code);
		propagate(k<<1|1, code);
		
	}
}

int querry(int k,int l,int r, int i,int j){
	laz(k,l,r);
	if(i>r||j<l) return 0;
	if(l>=i&&r<=j)return tree[k];
	int mid=(r+l)>>1;
	return querry(k<<1|1,mid+1,r,i,j)+querry(k<<1, l, mid, i, j);
}

void update(int k,int l,int r,int i,int j,char code){
	laz(k,l,r);
	if(i>r||j<l)return;
	if(l>=i&&r<=j){
		lazy[k]=code;
		laz(k, l, r);
	}
	else{
		int mid=(r+l)>>1;
		update(k<<1,l,mid,i,j,code);
		update(k<<1|1,mid+1,r,i,j,code);
		tree[k]=tree[k<<1]+tree[k<<1|1];
	}
}
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	REP(z,q){
		s="";
		int m; cin>>m;
		int t;
		string st;
		REP(i,m){
			cin>>t;
			cin>>st;
			REP(j,t){
				s.append(st);
			}
		}
		int q2; cin>>q2;
		tree=vi(s.length()*4);
		lazy=vector<char>(s.length()*4);
		build(1, 0, (int)s.length()-1);
		char c; int a,b;
		cout<<"Case "<<z+1<<":\n";
		int count=1;
		REP(i,q2){
			cin>>c>>a>>b;
			if(c!='S'){
				update(1, 0, (int)s.length()-1, a, b,c);
			}
			else{
				cout<<"Q"<<count<<": "<<querry(1, 0, (int)s.length()-1, a, b)<<"\n";
				count++;
			}
		}
	}

    return 0;
}
