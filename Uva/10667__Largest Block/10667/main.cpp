// UVa Online Judge 10667: Largest Block
//  10667
//	main.cpp
//  Created by David del Val on 16/08/2019
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

int arr[101][101];

int H[101][101];
int L[101][101];
int R[101][101];
void coutboard(int s){
	for(int i=0;i<s;++i){
		for(int j=0;j<s;++j){
			printf("%4d ",arr[i][j]);
		}
		printf("\n");
	}
	cout<<"\n---\n";
}
int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	REP(z,q){
		REP(i,101)REP(j,101)arr[i][j]=0;
		int s,n;
		cin>>s>>n;
		int r1,c1,r2,c2;
		REP(i, n){
			cin>>r1>>c1>>r2>>c2;
			r1--;
			c1--;
			r2--;
			c2--;
			for(int i=r1;i<=r2;++i){
				arr[i][c1]++;
				arr[i][c2+1]--;
			}
		}
		//coutboard(s);
		for(int i=0;i<s;++i){
			int csum=0;
			int counter=0;
			for(int j=0;j<s;++j){
				csum+=arr[i][j];
				if(!csum)arr[i][j]=++counter;
				else arr[i][j]=0;
			}
		}
		
		//coutboard(s);
		int ma=0;
		for(int x1=0;x1<s;++x1)for(int x2=0;x2<s;++x2){
			int counter=0;
			for(int y=0;y<s;++y){
				if(arr[y][x1]&&(x2==x1||arr[y][x2]-arr[y][x1]==x2-x1)){
					counter++;
				}
				else counter=0;
				ma=max(ma,counter*(x2-x1+1));
			}
		}
		cout<<ma<<"\n";
		
		
		
	}

    return 0;
}


