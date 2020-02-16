// UVa Online Judge 11800: Determine the Shape
//  11800
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

bool deg90(pii o, pii p1,pii p2){
	p1.fi-=o.fi;
	p1.se-=o.se;
	p2.fi-=o.fi;
	p2.se-=o.se;
	return p1.fi*p2.fi+p1.se*p2.se==0;
}
bool parallel(pii o1,pii f1, pii o2,pii f2){
	return ((double)o1.fi-f1.fi)/(o1.se-f1.se)==((double)o2.fi-f2.fi)/(o2.se-f2.se);
}
double dist(pii o,pii f){
	return sqrt(pow(o.fi-f.fi,2)+pow(o.se-f.se,2));
}
int main(){
    ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int z=1;z<=t;++z){
		vector<pii>da(4);
		cin>>da[0].fi>>da[0].se>>da[1].fi>>da[1].se>>da[2].fi>>da[2].se>>da[3].fi>>da[3].se;
		cout<<"Case "<<z<<": ";
		//Get center
		double px=da[0].fi+da[1].fi+da[2].fi+da[3].fi;
		px/=4;
		double py=da[0].se+da[1].se+da[2].se+da[3].se;
		py/=4;
		//Sort
		sort(da.begin(), da.end(),[px,py](pii a,pii b){
			double t1=atan2(a.fi-px,a.se-py);
			double t2=atan2(b.fi-px,b.se-py);
			double a1=((int)((t1+2*M_PI)*1000))%((int)(2*M_PI*1000));
			double a2=((int)((t2+2*M_PI)*1000))%((int)(2*M_PI*1000));
			return a1-a2<0;
		});
		
		if(parallel(da[0], da[1], da[3], da[2])&&parallel(da[0], da[3], da[1], da[2])){
			if(deg90(da[0],da[3],da[1])){
				//90 deg angles
				if(dist(da[0],da[1])==dist(da[0],da[3])){
					cout<<"Square\n";
				}
				else{
					cout<<"Rectangle\n";
				}
			}
			else{
				if(dist(da[0],da[1])==dist(da[0],da[3])){
					cout<<"Rhombus\n";
				}
				else{
					cout<<"Parallelogram\n";
				}
			}
		}
		else if(parallel(da[0], da[1], da[3], da[2])||parallel(da[0], da[3], da[1], da[2])){
			cout<<"Trapezium\n";
		}
		else{
			cout<<"Ordinary Quadrilateral\n";
		}
	}

    return 0;
}

