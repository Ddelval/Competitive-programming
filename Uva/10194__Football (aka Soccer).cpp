// UVa Online Judge 10194: Football (aka Soccer)
//  10194
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

struct Team{
	string name;
	int points;
	int win, tie,loss;
	int G,g;
	
	bool operator <(const Team& r) const{
		if(points < r.points)return false;
		if(points > r.points)return true;
		if(win<r.win) return false;
		if (win > r.win) return true;
		if(G-g < r.G-r.g) return false;
		if(G-g > r.G-r.g) return true;
		if(G < r.G) return false;
		if(G > r.G) return true;
		if(win+tie+loss>r.win+r.tie+r.loss) return false;
		if(win+tie+loss<r.win+r.tie+r.loss) return true;
		string nl;
		string nrl;
		for(char c:name)nl+=(tolower(c));
		for(char c:r.name)nrl+=(tolower(c));
		return nl<nrl;
	}
	Team(string s){
		name=s;
		points=win=tie=loss=G=g=0;
	}
	
};
vector<Team> data;
map<string,int> dic;
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	string ss;
	getline(cin,ss);
	REP(z,q){
		data.clear();
		dic.clear();
		string tourn;
		getline(cin,tourn);
		getline(cin,ss);
		int nteam=stoi(ss);
		REP(i,nteam){
			getline(cin,ss);
			data.pb(Team(ss));
			dic[ss]=i;
		}
		getline(cin,ss);
		int ngames=stoi(ss);
		REP(i,ngames){
			getline(cin,ss);
			string::iterator f=find(ss.begin(),ss.end(),'#');
			string tt1=ss.substr(0,f-ss.begin());
			string::iterator g=find(f,ss.end(),'@');
			int g1=stoi(ss.substr(f-ss.begin()+1,g-f-1));
			auto f2=f; f2++;
			f=find(f2,ss.end(),'#');
			string tt2=ss.substr(f-ss.begin()+1);
			int g2=stoi(ss.substr(g-ss.begin()+1,f-g-1));
			int t1=dic[tt1], t2=dic[tt2];
			
			data[t1].G+=g1;
			data[t1].g+=g2;
			data[t2].G+=g2;
			data[t2].g+=g1;
			if(g1>g2){
				data[t1].win++;
				data[t1].points+=3;
				data[t2].loss++;
			}
			else if(g1<g2){
				data[t2].win++;
				data[t2].points+=3;
				data[t1].loss++;
			}
			else{
				data[t1].tie++;
				data[t2].tie++;
				data[t1].points++;
				data[t2].points++;
			}
			
		}
		sort(data.begin(),data.end());
		
		cout<<tourn<<"\n";
		REP(i,data.size()){
			cout<<i+1<<") ";
			cout<<data[i].name<<" "<<data[i].points<<"p, "<<data[i].win+data[i].tie+data[i].loss<<"g";
			cout<<" ("<<data[i].win<<"-"<<data[i].tie<<"-"<<data[i].loss<<"), "<<data[i].G-data[i].g<<"gd (";
			cout<<data[i].G<<"-"<<data[i].g<<")\n";
		}
		if(z!=q-1)cout<<"\n";
	}

    return 0;
}

