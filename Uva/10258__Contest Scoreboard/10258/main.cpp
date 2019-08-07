// UVa Online Judge 10258: Contest_Scoreboard
//  10258
//	main.cpp
//  Created by David del Val on 03/08/2019
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
#include <sstream>
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

struct contestant {
	bool accepted[9];
	bool used;
	int ac;
	int penalty[9];
	int endtime[9];
	int time;
	int i;
	contestant(int i){
		REP(i,9){
			accepted[i]=false;
			penalty[i]=0;
			endtime[i]=0;
		}
		ac=-1;
		time=0;
		used=false;
		this->i=i;
	}
	void process();
	bool operator >(const contestant& c) const{
		if(ac>c.ac)return true;
		if(ac<c.ac)return false;
		if(time<c.time) return true;
		if(time>c.time) return false;
		return i<c.i;
	}
};

void contestant::process(){
	REP(i,9){
		ac+=accepted[i];
		if(accepted[i]){
			time+=20*penalty[i]+endtime[i];
		}
	}
}
vector<contestant> data;
int main(){
    ios::sync_with_stdio(false);
	int q;
	string s;
	getline(cin,s);
	q=stoi(s);
	getline(cin, s);
	REP(z,q){
		int con,prob,tim;
		char l;
		stringstream str;
		data.clear();
		data.reserve(100);
		REP(i,100){
			data.pb(contestant(i));
		}
		while(getline(cin,s)&&s!=""){
			str=stringstream(s);
			str>>con>>prob>>tim>>l;
			con--;
			if(data[con].ac==-1)data[con].ac=0;
			prob--;
			if(l=='C'){
				if(!data[con].accepted[prob]){
					data[con].accepted[prob]=true;
					data[con].endtime[prob]=tim;
				}
			}
			else if(l=='I'){
				if(!data[con].accepted[prob]){
					data[con].penalty[prob]++;
				}
			}
		}
		REP(i, 100)data[i].process();
		sort(data.begin(),data.end(),greater<contestant>());
		REP(i, 100){
			if(data[i].ac==-1)break;
			cout<<data[i].i+1<<" "<<data[i].ac<<" "<<data[i].time<<"\n";
		}
		if(z!=q-1)cout<<"\n";
	}

    return 0;
}

