// UVa Online Judge 10662: The Wedding
//  10662
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

vector<vector<int>>adyList[3];

int history[3],fin[3];
int res;
int val[3][20];
int ady[3][20][20];
void DFS(int layer,int cost,int cnode){
	if(layer==2){
		if(ady[layer][cnode][history[0]]){
			if(cost<res){
				res=cost;
				REP(i,3)fin[i]=history[i];
				
			}
		}
		return;
	}
	for(int a:adyList[layer][cnode]){
		history[layer+1]=a;
		DFS(layer+1,cost+val[layer+1][a],a);
	}
}
int main(){
    ios::sync_with_stdio(false);
	int t,r,h;
	while(cin>>t>>r>>h){
		for(int i=0;i<3;++i){
			for(int j=0;j<20;++j){
				for(int z=0;z<20;++z){
					ady[i][j][z]=0;
				}
			}
		}
		vector<vector<int>> v;
		adyList[0]=adyList[1]=adyList[2]=v;
		vector<int> av;
		for(int i=0;i<t;++i){
			cin>>val[0][i];
			adyList[0].pb(av);
			for(int j=0;j<r;j++){
				cin>>ady[0][i][j];
				ady[0][i][j]=!ady[0][i][j];
				if(ady[0][i][j]){
					adyList[0][i].pb(j);
				}
			}
		}
		for(int i=0;i<r;++i){
			cin>>val[1][i];
			adyList[1].pb(av);
			for(int j=0;j<h;j++){
				cin>>ady[1][i][j];
				ady[1][i][j]=!ady[1][i][j];
				if(ady[1][i][j]){
					adyList[1][i].pb(j);
				}
			}
		}
		for(int i=0;i<h;++i){
			cin>>val[2][i];
			adyList[2].pb(av);
			for(int j=0;j<t;j++){
				cin>>ady[2][i][j];
				ady[2][i][j]=!ady[2][i][j];
				if(ady[2][i][j]){
					adyList[2][i].pb(j);
				}
			}
		}
		res=INT_MAX;
		for(int i=0;i<t;++i){
			history[0]=i;
			DFS(0,val[0][i],i);
		}
		if(res==INT_MAX)cout<<"Don't get married!\n";
		else {
			cout<<fin[0]<<" "<<fin[1]<<" "<<fin[2]<<":"<<res<<"\n";
		}
	}

    return 0;
}

