//  0469
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

pii parent[100][100];
int rankk[100][100];
int size[100][100];
int w[100][100];
int n,m;
pii find(int i,int j){
	return parent[i][j]=(mp(i,j)==parent[i][j])? mp(i,j):find(parent[i][j].fi,parent[i][j].se);
}
void Union(int i,int j,int i2,int j2){
	pii p1=find(i,j);
	pii p2=find(i2,j2);
	if(p1==p2)return;
	else if(rankk[p1.fi][p1.se]>rankk[p2.fi][p2.se]){
		parent[p2.fi][p2.se]=parent[p1.fi][p1.se];
	}
	else if(rankk[p1.fi][p1.se]<rankk[p2.fi][p2.se]){
		parent[p1.fi][p1.se]=parent[p2.fi][p2.se];
	}
	else{
		parent[p2.fi][p2.se]=parent[p1.fi][p1.se];
		rankk[p1.fi][p1.se]++;
	}
}
void ini(){
	REP(i,n)REP(j,m){
		parent[i][j]=mp(i,j);
		rankk[i][j]=1;
	}
}
int main(){
    ios::sync_with_stdio(false);
	int q;
	string aaa;
	cin>>q;
	getline(cin,aaa);
	getline(cin,aaa);
	while(q--){
		n=m=100;
		char c;
		ini();
		string s;
		int i=0,j=0;
		while(getline(cin,s)&&s.size()>0&&(s[0]=='L'||s[0]=='W')){
			m=s.length();
			j=0;
			for(char c:s){
				size[i][j]=0;
				w[i][j]=(c=='W');
				if(!w[i][j]){
					j++;
					continue;
				}
				if(i){
					if(w[i-1][j-1])Union(i-1,j-1,i,j);
					if(w[i-1][j])Union(i-1,j,i,j);
					if(j!=m-1&&w[i-1][j+1])Union(i-1,j+1,i,j);
				}
				if(j){
					if(w[i][j-1])Union(i,j-1,i,j);
				}
				
				j++;
			}
			i++;
		}
		
		REP(i,n)REP(j,m){
			size[find(i,j).fi][find(i,j).se]++;
		}
		while(s!=""){
			string::size_type a;
			int i=stoi(s,&a,10);
			s=s.substr(a);
			int j=stoi(s);
			i--;
			j--;
			cout<<size[parent[i][j].fi][parent[i][j].se]<<"\n";
			getline(cin,s);
		}
		if(q)cout<<"\n";

	}

    return 0;
}


