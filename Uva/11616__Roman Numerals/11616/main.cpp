// UVa Online Judge 11616: Roman Numerals
//  11616
//	main.cpp
//  Created by David del Val on 09/08/2019
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

string rom[4][9]={
	{
		"I","II","III","IV","V","VI","VII","VIII","IX"
	},
};

int main(){
    ios::sync_with_stdio(false);
	transform(rom[0], rom[0]+9, rom[1], [](string s){
		transform(s.begin(),s.end(),s.begin(),[](char &c){
			if(c=='I')return 'X';
			else if(c=='X')return 'C';
			else return 'L';
		});
		return s;
	});
	transform(rom[0], rom[0]+9, rom[2], [](string s){
		transform(s.begin(),s.end(),s.begin(),[](char &c){
			if(c=='I')return 'C';
			else if(c=='X')return 'M';
			else return 'D';
		});
		return s;
	});
	transform(rom[0], rom[0]+3, rom[3], [](string s){
		transform(s.begin(),s.end(),s.begin(),[](char &c){
			if(c=='I')return 'M';
			else return 'L';
		});
		return s;
	});
	map<string,int> rev;
	int t3=1;
	for(int i=0;i<4;++i){
		for(int j=0;j<9;++j){
			if(rom[i][j]!="")rev.insert(mp(rom[i][j],t3*(j+1)));
		}
		t3*=10;
	}
	string s;
	while(getline(cin,s)){
		try {
			string out;
			int i=stoi(s);
			if(!i)throw exception();
			int count=0;
			while(i>0){
				if(i%10-1>-1)out=rom[count][i%10-1 ]+out;
				i/=10;
				count++;
			}
			cout<<out<<"\n";
		
		
		} catch (exception a) {
			int val=0;
			for(int i=0;i<s.length();++i){
				for(int j=4;j>0;j--){
					if(i+j<=s.length()){
						auto itt=rev.find(s.substr(i,j));
						if(itt!=rev.end()){
							val+=itt->second;
							i+=j-1;
							break;
						}
					}
				}
				
			}
			cout<<val<<"\n";
			
			
		}
		
		
		
		
	}
    return 0;
}

