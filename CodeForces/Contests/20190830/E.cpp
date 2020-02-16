//  E
//	main.cpp
//  Created by David del Val on 30/08/2019
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

bool ady[3][3];
int main(){
    ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	cout<<"YES\n";
	ady[s[0]-'a'][s[1]-'a']=true;
	ady[t[0]-'a'][t[1]-'a']=true;
	for(int i=0;i<3;++i){
		if((ady[(i+1)%3][i]&&ady[(i+2)%3][i])){
			for(int j=0;j<n;++j){
				cout<<(char)('a'+i);
			}
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+1)%3);
			}
			
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+2)%3);
			}
			
			return 0;
		}
		if((ady[i][(i+1)%3]&&ady[i][(i+2)%3])){
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+1)%3);
			}
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+2)%3);
			}
			for(int j=0;j<n;++j){
				cout<<(char)('a'+i);
			}
			return 0;
		}
		if((ady[(i+1)%3][i]&&ady[i][(i+1)%3])){
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+1)%3);
			}
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+2)%3);
			}
			for(int j=0;j<n;++j){
				cout<<(char)('a'+i);
			}
			return 0;
		}
		if (ady[i][(i+2)%3]&&ady[(i+2)%3][i]){
			for(int j=0;j<n;++j){
				cout<<(char)('a'+i);
			}
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+1)%3);
			}
			for(int j=0;j<n;++j){
				cout<<(char)('a'+(i+2)%3);
			}
			
			return 0;
		}
	}
	if(!ady[0][1]&&!ady[1][2]&&!ady[2][0]){
		REP(i,n)cout<<"abc";
	}
	else{
		REP(i,n)cout<<"acb";
	}
	
    return 0;
}


