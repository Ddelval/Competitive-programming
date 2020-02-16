//  1
//	main.cpp
//  Created by David del Val on 18/07/2019
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
typedef pair<double,double> pdd;
typedef pair<ll, ll> pll;
#define lim 100005

bool aligned(pii p1,pii p2,pii p3){
	//return (p3.second-p2.second)*(p2.first-p1.first)==(p2.second-p1.se)*(p3.first-p2.first);
	return !((ll)p1.first*(p2.second-p3.second)+(ll)p2.first*(p3.second-p1.second)+(ll)p3.first*(p1.second-p2.second));
}

pii points[lim];
int n;

int main(){
    ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		pii a;
		cin>>a.first>>a.second;
		points[i]=a;
	}
	if(n<4){
		cout<<"YES";
		return 0;
	}
	pii rem;
	pii c1,c2;
	int ab=5;
	if(aligned(points[1],points[2],points[3])){
		int j=4;
		while(j<=n&&aligned(points[1],points[2],points[j])){
			j++;
		}
		if(j==n+1){
			cout<<"YES";
			return 0;
		}
		ab=j+1;
		rem=points[j];
		c1=points[1];
		c2=points[2];
	}
	
	else if(aligned(points[1],points[2],points[4])){
		rem=points[3];
		c1=points[1];
		c2=points[2];
	}
	else if(aligned(points[1],points[3],points[4])){
		rem=points[2];
		c1=points[1];
		c2=points[4];
	}
	else if(aligned(points[3],points[2],points[4])){
		rem=points[1];
		c1=points[3];
		c2=points[2];
	}
	else{
		pdd l1,l2;
		bool b= true;
		for(int i=1;i<=n;++i){
			if(aligned(points[1], points[2], points[i])||aligned(points[3],points[4],points[i])){
			}
			else{
				b=false;
				break;
			}
		}
		if(b){
			cout<<"YES";
			return 0;
		}
		b=true;
		for(int i=1;i<=n;++i){
			if(aligned(points[1], points[3], points[i])||aligned(points[2],points[4],points[i])){
			}
			else{
				b=false;
				break;
			}
		}
		if(b){
			cout<<"YES";
			return 0;
		}
		b=true;
		for(int i=1;i<=n;++i){
			if(aligned(points[1], points[4], points[i])||aligned(points[2],points[3],points[i])){
			}
			else{
				b=false;
				break;
			}
		}
		if(b){
			cout<<"YES";
			return 0;
		}
		cout<<"NO";
		return 0;
	}
	int j=ab;
	while(j<=n&&aligned(c1,c2,points[j]))j++;
	if(j==n+1){
		cout<<"YES";
	}
	else{
		for(int w=j+1;w<=n;++w){
			if((!aligned(c1,c2,points[w]))&&!(aligned(rem,points[j],points[w]))){
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
	

    return 0;
}

