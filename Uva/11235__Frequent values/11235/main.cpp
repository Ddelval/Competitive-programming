// UVa Online Judge 11235: Frequent values
//  11235
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
struct node{
	pii sm;
	pii med;
	pii big;
	node(pii a,pii b,pii c){
		sm=a;
		med=b;
		big=c;
	}
	node(){
		sm={-1,0};
	}
};
vector<node> tree;
vi v;
node merge(node n1,node n2){
	node n;
	n.big=n2.big;
	n.sm=n1.sm;
	vector<pii> v;
	v.pb(n1.sm);
	v.pb(n1.med);
	if(n1.big.se==n2.sm.se)v.pb(mp(n1.big.fi+n2.sm.fi,n1.big.se));
	else{
		v.pb(n1.big); v.pb(n2.sm);
	}
	v.pb(n2.med);
	v.pb(n2.big);
	n.med=*max_element(v.begin(),v.end());
	if(n.med.se==n.big.se)n.big.fi=n.med.fi;
	if(n.med.se==n.sm.se)n.sm.fi=n.med.fi;
	return n;
}
void build(int k,int l,int r){
	if(l==r){
		node n;
		n.big=n.med=n.sm=mp(1,v[l]);
		tree[k]=n;
		return ;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k]=merge(tree[k<<1],tree[k<<1|1]);
}
node querry(int k,int l, int r, int i, int j){
	if(i>r||j<l) return node(); //No overlap
	if(l>=i&&r<=j)return tree[k];
	int mid=(l+r)>>1;
	node a1=querry(k<<1,l,mid,i,j);
	node a2=querry(k<<1|1,mid+1,r,i,j);
	if(a1.sm.fi==-1)return a2;
	if(a2.sm.fi==-1)return a1;
	return merge(a1,a2);
}

int main(){
    ios::sync_with_stdio(false);
	int n,q;
	while(cin>>n>>q&&n){
		v=vi(n);
		REP(i,n)cin>>v[i];
		tree=vector<node>(4*n);
		build(1,0,n-1);
		int a,b;
		REP(i,q){
			cin>>a>>b;
			a--; b--;
			node nn=querry(1,0,n-1,a,b);
			cout<<max(nn.big.fi,max(nn.med.fi,nn.sm.fi))<<"\n";
		}
	}
    return 0;
}


