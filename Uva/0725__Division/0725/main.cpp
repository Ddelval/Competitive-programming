// UVa Online Judge 725: Division
//  0725
//	main.cpp
//  Created by David del Val on 08/08/2019
//
//


#include <bits/stdc++.h>

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
bool dig[10];
int di;
int c_i;
bool check(int n,int n2){
	if(n<10000&&n2<10000)return false;
	for(c_i=0;c_i<10;++c_i)dig[c_i]=0;
	if(n<10000||n2<10000)dig[0]=true;
	while(n>0){
		di=n%10;
		if(dig[di])return false;
		else dig[di]=true;
		n/=10;
	}
	n=n2;
	while(n>0){
		di=n%10;
		if(dig[di])return false;
		else dig[di]=true;
		n/=10;
	}
	return true;
}

int main(){
    ios::sync_with_stdio(false);
	int a;
	bool f=false;
	while(cin>>a&&a){
		if(f)cout<<"\n";
		f=true;
		bool sol=false;
		for(int num=1234;num<=98745;++num){
			if(check(num,a*num)){
				cout<<a*num<<" / "<< ((num<10000)? "0":"")<<num<<" = "<<a<<"\n";
				sol=true;
			}
		}
		if(!sol){
			cout<<"There are no solutions for "<<a<<".\n";
		}
	}

    return 0;
}

