// UVa Online Judge 836: Largest Submatrix
//  0836
//	main.cpp
//  Created by David del Val on 16/08/2019
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

int mat[26][26];

int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	string s;
	getline(cin,s);
	getline(cin,s);
	REP(z,q){
		//REP(i,26)REP(j,26)mat[i][j]=0;
		int lin=0;
		int n=0;
		while(getline(cin,s)&&s!=""){
			int counter=0;
			for(int i=0;i<s.length();++i){
				n=(int)s.length();
				if(s[i]=='0'){
					counter=0;
				}
				else counter++;
				mat[lin][i]=counter;
			}
			lin++;
		}
		int ma=0;
		for(int x1=0;x1<n;++x1) for(int x2=x1;x2<n;x2++){
			int counter=0;
			for(int y=0;y<lin;++y){
				if((x1!=x2&&mat[y][x2]-mat[y][x1]==x2-x1&&mat[y][x1]>0)||(x1==x2&&mat[y][x2]))counter++;
				else counter=0;
				ma=max(ma,counter*(x2-x1+1));
			}
		}
		cout<<ma<<"\n";
		if(z!=q-1)cout<<"\n";
		
		
	}

    return 0;
}


