// UVa Online Judge 11297: Census
//  11297
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
const long lim=500*4;
pii tree[lim][lim];
int v[500][500];
int m,n;
pii me(pii a1, pii a2){
	pii res;
	res.se=min(a1.se,a2.se);
	res.fi=max(a1.fi,a2.fi);
	return res;
}
void buildy(int kx,int lx,int rx, int ky,int ly,int ry){
	if(ly==ry){
		if(rx==lx){
			tree[kx][ky]=mp(v[lx][ly],v[lx][ly]);
		}
		else{
			tree[kx][ky]=me(tree[kx*2][ky],tree[(kx*2)+1][ky]);
			//tree[kx][ky].se=min(tree[kx*2][ky].se,tree[(kx*2)+1][ky].se);
			//tree[kx][ky].fi=max(tree[kx*2][ky].fi,tree[(kx*2)+1][ky].fi);
		}
	}
	else{
		int mid=(ly+ry)/2;
		buildy(kx,lx,rx,ky*2,ly,mid);
		buildy(kx,lx,rx,(ky*2)+1,mid+1,ry);
		tree[kx][ky]=me(tree[kx][ky*2],tree[kx][ky*2+1]);
		//tree[kx][ky].se=min(tree[kx][ky*2].se,tree[kx][(ky*2)+1].se);
		//tree[kx][ky].fi=max(tree[kx][ky*2].fi,tree[kx][(ky*2)+1].fi);
	}
}
void buildx(int kx,int lx,int rx){
	if(lx!=rx){
		int mid=(lx+rx)/2;
		buildx(kx*2, lx, mid);
		buildx((kx*2)+1,mid+1,rx);
	}
	buildy(kx,lx,rx,1,0,m-1);
}
pii querry_y(int kx,int ky, int qly,int qry, int ly,int ry){
	if(ly>qry||ry<qly)return mp(INT_MIN,INT_MAX);
	if(ly>=qly&&ry<=qry){
		return tree[kx][ky];
	}
	int med=(ly+ry)/2;
	return me(querry_y(kx,ky*2,qly,qry,ly,med),querry_y(kx,ky*2+1,qly,qry,med+1,ry));
	
}
pii querry_x(int kx,int qly,int qry,int qlx,int qrx, int lx, int rx){
	if(lx>qrx||rx<qlx)return mp(INT_MIN,INT_MAX);
	if(lx>=qlx&&rx<=qrx) return querry_y(kx, 1, qly, qry, 0, m-1);
	int mid=(lx+rx)/2;
	return me(querry_x(kx*2, qly, qry, qlx, qrx, lx, mid),querry_x(kx*2+1, qly, qry, qlx, qrx, mid+1, rx));
}
void update_y(int kx,int ky, int lx, int rx,int ly,int ry, int x,int y, int inc){
	if(ly==ry){
		if(lx==rx){
			tree[kx][ky].fi=inc;
			tree[kx][ky].se=inc;
		}
		else{
			tree[kx][ky]=me(tree[kx*2][ky],tree[(kx*2)+1][ky]);
		}
	}
	else{
		int mid=(ly+ry)/2;
		if(y<=mid) 	update_y(kx, ky*2,   lx, rx,  ly, mid, x, y, inc);
		else		update_y(kx, ky*2+1, lx, rx, mid+1,  ry, x, y, inc);
		tree[kx][ky]=me(tree[kx][ky*2],tree[kx][ky*2+1]);
	}
}
void update_x(int kx,int lx,int rx,int x,int y, int inc){
	if(lx!=rx){
		int mid=(lx+rx)/2;
		if(x<=mid)update_x(kx*2, lx, mid, x, y, inc);
		else update_x(kx*2+1, mid+1, rx, x, y, inc);
	}
	update_y(kx, 1, lx, rx, 0, m-1, x, y, inc);
}
int main(){
    ios::sync_with_stdio(false);
	cin>>n;
	m=n;
	REP(i,n){
		REP(j,n){
			cin>>v[i][j];
		}
	}
	buildx(1,0,n-1);
	int q;
	cin>>q;
	REP(z,q){
		char c;
		cin>>c;
		if(c=='q'){
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			x1--;
			x2--;
			y1--;
			y2--;
			auto a=querry_x(1, y1, y2, x1, x2, 0, n-1);
			cout<<a.fi<<" "<<a.se<<"\n";
		}
		else{
			int x,y,val;
			cin>>x>>y>>val;
			x--;
			y--;
			update_x(1, 0, m-1, x, y, val);
		}
	}
    return 0;
}

