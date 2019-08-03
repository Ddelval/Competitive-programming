//  10158
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
#define parent(i) sets[i].parent
#define enemy(i) sets[i].enemy
#define rank(i) sets[i].rank
struct dset {
	int parent;
	int enemy;
	int rank;
};
vector<dset>sets;
int find(int i){
	while(parent(i)!=parent(parent(i))){
		parent(i)=parent(parent(i));
	}
	return parent(i);
}
int find_e(int i){
	int ip=find(i);
	if(enemy(ip)==-1){
		return -1;
	}
	else{
		enemy(ip)=find(enemy(ip));
		return enemy(ip);
	}
}
void Union(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rank(x)>rank(y)){
		int e1=find_e(x);
		int e2=find_e(y);
		parent(y)=parent(x);
		if(e1!=e2&&e1!=-1&&e2!=-1){
			enemy(e1)=parent(x);
			enemy(e2)=parent(x);
			Union(e1,e2);
		}
		else if(e1==-1){
			enemy(x)=e2;
		}
	}
	else if(rank(x)<rank(y)){
		int e1=find_e(x);
		int e2=find_e(y);
		parent(x)=parent(y);
		if(e1!=e2&&e1!=-1&&e2!=-1){
			enemy(e1)=parent(y);
			enemy(e2)=parent(y);
			Union(e1,e2);
		}
		else if(e2==-1){
			enemy(y)=e1;
		}
	}
	else{
		int e1=find_e(x);
		int e2=find_e(y);
		parent(x)=parent(y);
		rank(y)++;
		if(e1!=e2&&e1!=-1&&e2!=-1){
			enemy(e1)=parent(y);
			enemy(e2)=parent(y);
			Union(e1,e2);
		}
		else if(e2==-1){
			enemy(y)=e1;
		}
	}
}
bool friends(int x,int y){
	return find(x)==find(y);
}
bool enemies(int x,int y){
	return find_e(find(x))==find(y);
}
int setFriend(int x,int y){
	int px=find(x);
	int py=find(y);
	if(enemies(px, py))return -1;
	else Union(px,py);
	return 0;
}
int setEnemy(int x,int y){
	int px=find(x);
	int py=find(y);
	int ex=find_e(x);
	int ey=find_e(y);
	if(friends(px,py))return -1;
	if(ex==-1&&ey==-1){
		enemy(px)=py;
		enemy(py)=px;
		return 0;
	}
	if(ex==-1){
		enemy(px)=py;
		Union(px,ey);
		return 0;
	}
	if(ey==-1){
		enemy(py)=px;
		Union(py,ex);
		return 0;
	}
	else if(ex!= py){
		if(friends(ex,py))return 0;
		if(enemies(ex, py))return -1;
		Union(ex, py);
	}
	return 0;
}
void start(int n){
	sets=vector<dset>(n);
	REP(i,n){
		parent(i)=i;
		rank(i)=1;
		enemy(i)=-1;
	}
}
int main(){
    ios::sync_with_stdio(false);
	int n;
	cin>>n;
	start(n);
	int c,x,y;
	while(cin>>c>>x>>y&&c){
		switch (c) {
			case 1:
				if(setFriend(x, y)==-1){
					cout<<"-1\n";
				}
				break;
				
			case 2:
				if(setEnemy(x, y)==-1){
					cout<<"-1\n";
				}
				break;
			case 3:
				cout<<friends(x, y)<<"\n";
				break;
			case 4:
				cout<<enemies(x, y)<<"\n";
				break;
			default:
				break;
		}
	}

    return 0;
}
