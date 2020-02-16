//  1201D
//	main.cpp
//  Created by David del Val on 05/08/2019
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

int n,m,k,q;
vi safe;
vi rightt,leftt;
map<int,int> mapd;
map<int,int> mapd2;
ll r1,l1,r2,l2;
pll res[4];
pll tmp[4];
void findColumns(){
	for(int a:rightt)mapd[a]=INT_MIN/2;
	
	for(int a:leftt)mapd[a]=INT_MIN/2;
	
	sort(safe.begin(),safe.end());
	mapd2=mapd;
	
	auto it=mapd.begin();
	int prev=INT_MIN/2;
	REP(i,q){
		for(; it!=mapd.end()&&safe[i]>it->fi ; it++) it->se=prev;
		if(it==mapd.end())break;
		prev=safe[i];
	}
	for(; it!=mapd.end() ; it++) it->se=prev;
	
	auto it2=mapd2.rbegin();
	prev=INT_MIN/2;
	for(int i=q-1;i>=0;i--){
		for(; it2!=mapd2.rend()&&safe[i]<it2->fi ; it2++) it2->se=prev;
		if(it2==mapd2.rend())break;
		prev=safe[i];
	}
	for(; it2!=mapd2.rend() ; it2++) it2->se=prev;
	
}

void explore(int level){
	if(rightt[level]<0)return;
	
	tmp[0].fi=r1=mapd [rightt[level]];
	tmp[1].fi=r2=mapd2[rightt[level]];
	tmp[2].fi=l1=mapd [leftt[level]];
	tmp[3].fi=l2=mapd2[leftt[level]];
	REP(i,4) tmp[i].se=LLONG_MAX/2;
	
	REP(z,4){
		ll ini=res[z].fi;
		if(ini<0)continue;
		//Go right then left
		tmp[2].se=min(tmp[2].se,res[z].se+ ini-leftt[level] + ((ini<rightt[level])? 2*(rightt[level]-ini) : 0) + abs(leftt[level]-l1));
		tmp[3].se=min(tmp[3].se,res[z].se+ ini-leftt[level] + ((ini<rightt[level])? 2*(rightt[level]-ini) : 0) + abs(leftt[level]-l2));
		//Go left then right
		tmp[0].se=min(tmp[0].se,res[z].se+ rightt[level]-ini+ ((ini>leftt[level])? 2*(ini-leftt[level]) : 0)   + abs(rightt[level]-r1));
		tmp[1].se=min(tmp[1].se,res[z].se+ rightt[level]-ini+ ((ini>leftt[level])? 2*(ini-leftt[level]) : 0)   + abs(rightt[level]-r2));
	}
	REP(i,4)res[i]=tmp[i];
}

ll explorelast(int level){
	ll finalcost=LLONG_MAX;
	if(rightt[level]<0) return min(res[0].se,min(res[1].se,min(res[2].se,res[3].se)));
	
	REP(z, 4){
		ll ini=res[z].fi;
		if(ini<0)continue;
		//Go right then left
		finalcost=min(finalcost, res[z].se-leftt[level]+ini+( (ini<rightt[level])? 2*(rightt[level]-ini):0 ));
		//Go left then right
		finalcost=min(finalcost, res[z].se+rightt[level]-ini+( (ini>leftt[level])? 2*(ini-leftt[level]):0 ));
	}
	return finalcost;
}

int main(){
    ios::sync_with_stdio(false);
	cin>>n>>m>>k>>q;
	rightt=vi();
	leftt=vi();
	rightt.assign(n, -2);
	leftt.assign(n, m+2);
	int a,b;
	int ma=INT_MIN;
	REP(z,k){
		cin>>b>>a;
		a--;
		b--;
		ma=max(ma,b);
		if(rightt[b]<a)rightt[b]=a;
		if(leftt[b]>a)leftt[b]=a;
	}
	leftt[0]=0;
	if(rightt[0]<0)rightt[0]=0;
	ma++;
	n=ma;
	safe=vi(q);
	REP(i,q){
		cin>>safe[i];
		safe[i]--;
	}
	
	findColumns();
	
	res[0].fi=0;
	res[0].se=0;
	res[1].fi=-1;
	res[2].fi=-1;
	res[3].fi=-1;
	REP(i,n-1){
		explore(i);
	}
	cout<<explorelast(n-1)+(n-1);
	
    return 0;
}

