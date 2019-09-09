//  0782
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

int n,m;
char board[100][100];
bool visited[100][100];
int dfs(int i,int j){
	if(i<0||i>=n)return 0;
	if(j<0||j>=m)return 0;
	if(visited[i][j])return 0;
	if(board[i][j]!='#'&&board[i][j]!=' '&&board[i][j]!='*'&&board[i][j]!='_'&&board[i][j]!=0)return 1;
	int r=0;
	visited[i][j]=true;
	r=dfs(i-1,j)+dfs(i+1,j)+dfs(i,j+1)+dfs(i,j-1);
	if(r)board[i][j]='#';
	return 0;
}
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	string s;
	getline(cin,s);
	
	while(q--){
		REP(i,30)REP(j,80)board[i][j]=0;
		n=m=0;
		while(getline(cin,s)&&(s.length()<1||s[0]!='_')){
			if(s.length()<1){
				n++;
				continue;
			}
			
			m=max((int)s.length(),m);
			int j=0;
			for(char a:s){
				board[n][j]=a;
				j++;
			}
			n++;
		}
		m++;
		REP(i,n)REP(j,m){
			if(board[i][j]==0){
				board[i][j]=' ';
			}
			visited[i][j]=false;
		}
		bool bs=false;
		REP(i,n){
			REP(j,m){
			if(board[i][j]=='*'){
				board[i][j]=' ';
				dfs(i,j);
				bs=true;
				
				break;
			}
				if(bs)break;
			}
		}
		bool ch=false;
	REP(i,n){
		string s="";
		REP(j,m){
			ch=true;
			s.push_back(board[i][j]);
		}
		string a="";
		bool b=true;
		for(int i=(int)s.length()-1;i>=0;--i){
			if(b&&s[i]==' ')continue;
			a.push_back(s[i]);
			b=false;
		}
		reverse(a.begin(), a.end());
		cout<<a;
		cout<<"\n";
	}
		if(ch)cout<<s<<"\n";
		
	}

    return 0;
}


