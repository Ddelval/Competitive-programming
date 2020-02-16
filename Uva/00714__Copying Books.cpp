// UVa Online Judge 714: Copying Books
//  0714
//	main.cpp
//  Created by David del Val on 10/08/2019
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
vector<int> books;
int k,m;
bool check(ll n){
	int kc=k;
	ll csum=0;
	for(int a:books){
		csum+=a;
		if(csum>n){
			csum=a;
			kc--;
			if(kc<=0){
				return false;
			}
		}
	}
	return true;
}


int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	REP(z,q){
		cin>>m>>k;
		books=vi(m);
		ll r,l;
		l=1;
		r=0;
		REP(i,m){
			cin>>books[i];
			l=max(l,(ll)books[i]);
			r+=books[i];
		}
		l--;
		//sort(books.begin(), books.end(),greater<int>());
		reverse(books.begin(),books.end());
		while(r-l>1){
			ll mid=(r+l)/2;
			if(check(mid))r=mid;
			else l=mid;
		}
		int kc=k;
		vi lims;
		ll csum=0;
		REP(i,books.size()){
			int a=books[i];
			csum+=a;
			if(csum>r){
				lims.pb(i);
				csum=a;
				kc--;
			}
		}
		for(int &a:lims)a=(int)books.size()-a;
		reverse(lims.begin(),lims.end());
		reverse(books.begin(),books.end());
		if(kc==1){
			int index=0;
			REP(i,books.size()){
				if(i)cout<<" ";
				if(i==lims[index]){
					cout<<"/ ";
					index++;
				}
				cout<<books[i];
				
			}
		}
		else{
			int index=0;
			REP(i,books.size()){
				if(i)cout<<" ";
				if(i==lims[index]){
					cout<<"/ ";
					index++;
				}
				else if(i&&kc>1){
					cout<<"/ ";
					kc--;
				}
				cout<<books[i];
				
			}
		}
		
		cout<<"\n";
	}

    return 0;
}

