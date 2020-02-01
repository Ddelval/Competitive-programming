//  9
//	main.cpp
//  Created by David del Val on 10/09/2019
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

#define A1(x) s1.insert(x);
#define A2(x) s2.insert(x);

int main(){
    ios::sync_with_stdio(false);
	set<string> s1,s2;
	
	A1("H")
	A2("LI")
	A2("NA")
	A1("K")
	A2("RB")
	A2("CS")
	A2("FR")
	A2("BE")
	A2("MG")
	A2("CA")
	A2("SR")
	A2("BA")
	A2("RA")
	A2("SC")
	A1("Y")
	A2("TI")
	A2("ZR")
	A2("HF")
	A2("RF")
	A2("LA")
	A2("AC")
	A1("V")
	A2("NB")
	A2("TA")
	A2("DB")
	A2("CE")
	A2("TH")
	A2("CR")
	A2("MO")
	A1("W")
	A2("SG")
	A2("PR")
	A2("PA")
	A2("MN")
	A2("TC")
	A2("RE")
	A2("BH")
	A2("ND")
	A1("U")
	A2("FE")
	A2("RU")
	A2("OS")
	A2("HS")
	A2("PM")
	A2("NP")
	A2("CO")
	A2("RH")
	A2("IR")
	A2("MT")
	A2("SM")
	A2("PU")
	A2("NI")
	A2("PD")
	A2("PT")
	A2("DS")
	A2("EU")
	A2("AM")
	A2("CU")
	A2("AG")
	A2("AU")
	A2("RG")
	A2("GD")
	A2("CM")
	A2("ZN")
	A2("CD")
	A2("HG")
	A2("CN")
	A2("TB")
	A2("BK")
	A1("B")
	A2("AL")
	A2("GA")
	A2("IN")
	A2("TL")
	A2("NH")
	A2("DY")
	A2("CF")
	A1("C")
	A2("SI")
	A2("GE")
	A2("SN")
	A2("PB")
	A2("FL")
	A2("HO")
	A2("ES")
	A1("N")
	A1("P")
	A2("AS")
	A2("SB")
	A2("BI")
	A2("MC")
	A2("ER")
	A2("FM")
	A1("O")
	A1("S")
	A2("SE")
	A2("TE")
	A2("PO")
	A2("LV")
	A2("TM")
	A2("MD")
	A1("F")
	A2("CL")
	A2("BR")
	A1("I")
	A2("AT")
	A2("TS")
	A2("YB")
	A2("NO")
	A2("HE")
	A2("NE")
	A2("AR")
	A2("KR")
	A2("XE")
	A2("RN")
	A2("OG")
	A2("LU")
	A2("LR")
	
	string l;
	while(getline(cin,l)){
		string g;
		for(char c:l){
			if(c==' ')continue;
			if(c<='Z')g.pb(c);
			else g.pb(c-'a'+'A');
		}
		bool possible[g.length()+1];
		for(int i=0;i<g.length();++i)possible[i]=false;
		possible[g.length()]=true;
		for(int r=(int)g.size()-1;r>=0;r--){
			if(r+1<g.length()){
				if(s2.count(g.substr(r,2))&&possible[r+2])possible[r]=true;
			}
			if(!possible[r]){
				if(s1.count(g.substr(r,1))&&possible[r+1])possible[r]=true;
			}
		}
		cout<<(possible[0]? "SI": "NO");
		cout<<"\n";
	}
	
	
	

    return 0;
}
