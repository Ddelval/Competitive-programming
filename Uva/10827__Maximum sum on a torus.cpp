// UVa Online Judge 10827: Maximum sum on a torus
//  10827
//	main.cpp
//  Created by David del Val on 17/08/2019
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

int arr[160][160];

int msums[160][160];
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	REP(z,q){
		int n;
		cin>>n;
		int a,sum;
		REP(i,n){
			REP(j,n){
				cin>>a;
				arr[i][j]=arr[i+n][j]=arr[i][j+n]=arr[i+n][j+n]=a;
			}
		}
		REP(i,2*n){
			REP(j,2*n){
				sum=arr[i][j];
				if(j)sum+=arr[i][j-1];
				arr[i][j]=sum;
				//if(i)sum+=arr[i-1][j];
			}
		}
		int ma=INT_MIN;
		for(int x1=0;x1<n;x1++) for(int x2=x1;x2<x1+n;x2++){
			int csum=0;
			int tsum=0;
			for(int y=0;y<n;y++){
				int tmp=arr[y][x2];
				if(x1)tmp-=arr[y][x1-1];
				tsum+=tmp;
				csum+=tmp;
				ma=max(ma,csum);
				if(csum<=0){
					csum=0;
				}
			}
			msums[x1][x2]=tsum;
			
		}
		REP(i,2*n){
			REP(j,2*n){
				arr[i][j]=-arr[i][j];
			}
		}
		for(int x1=0;x1<n;x1++) for(int x2=x1;x2<x1+n;x2++){
			int csum=0;
			int maa=INT_MIN;
			for(int y=0;y<n;y++){
				int tmp=arr[y][x2];
				if(x1)tmp-=arr[y][x1-1];
				csum+=tmp;
				maa=max(maa,csum);
				if(csum<=0){
					csum=0;
				}
			}
			int ch=msums[x1][x2]+maa;
			if (ch<=0)ch=INT_MIN;
			ma=max(ma,ch);
			
		}
		
		cout<<ma<<"\n";
	}

    return 0;
}


