//  0657
//	main.cpp
//  Created by David del Val on 24/08/2019
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
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
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

int board[50][50];
bool visited[50][50];
bool visited2[50][50];
int n,m;
void dfs2(int i,int j){
	if(i<0||i>n)return;
	if(j<0||j>m)return;
	if(visited2[i][j])return;
	if(board[i][j]==0)return;
	if(board[i][j]==1)return;
	visited2[i][j]=true;
	dfs2(i-1,j);
	dfs2(i+1,j);
	dfs2(i,j-1);
	dfs2(i,j+1);
}
int dfs(int i,int j){
	if(i<0||i>n)return 0;
	if(j<0||j>m)return 0;
	if(visited[i][j])return 0;
	if(board[i][j]==0)return 0;
	visited[i][j]=true;
	if(board[i][j]==2&&!visited2[i][j]){
		dfs2(i,j);
		return 1+dfs(i-1,j)+dfs(i+1,j)+dfs(i,j-1)+dfs(i,j+1);
	}
	
	return dfs(i-1,j)+dfs(i+1,j)+dfs(i,j-1)+dfs(i,j+1);
	
}

int main(){
    ios::sync_with_stdio(false);
	int count=0;
	while(cin>>m>>n&&n&&m){
		//if(count)cout<<"\n";
		char c;
		REP(i,n)REP(j,m){
			visited[i][j]=false;
			visited2[i][j]=false;
			cin>>c;
			if(c=='.')board[i][j]=0;
			else if(c=='*')board[i][j]=1;
			else board[i][j]=2;
		}
		vi res;
		REP(i,n)REP(j,m){
			if(!visited[i][j]&&board[i][j]){
				res.pb(dfs(i,j));
			}
		}
		sort(all(res));
		count++;
		cout<<"Throw "<<count<<"\n";
		bool b=false;
		for(auto a:res){
			if(b)cout<<" ";
			b=true;
			cout<<a;
		}
		cout<<"\n\n";
	}

    return 0;
}


