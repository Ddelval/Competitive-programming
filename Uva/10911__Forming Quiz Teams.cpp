// UVa Online Judge 10911: Forming Quiz Teams
//  10911
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

vector<bool>choose;
double mi;
int n;
vii points;
int lim;
long const ma=(2<<15)+1;
double arr[ma];
double dis[20][20];
double dist(int i,int j){
	if(dis[i][j]!=-1) return dis[i][j];
	return dis[i][j]=sqrt(pow(points[i].fi-points[j].fi,2)+pow(points[i].se-points[j].se,2));
}
double calculate(int mask){
	if(mask==lim)return 0;
	if (arr[mask]!=-1)return arr[mask];
	int i;
	for(i=n-1;i>=0;--i){
		if(!(mask&(1<<i)))break;
	}
	double res=INT_MAX;
	int pmask=mask;
	mask=mask|(1<<i);
	for(int j=i-1;j>=0;--j){
		if(!(mask&(1<<j))){
			res=min(res,calculate(mask|(1<<j))+dist(i,j));
		}
	}
	return arr[pmask]=res;
}

int main(){
    ios::sync_with_stdio(false);
	int counter=0;
	while(cin>>n&&n){
		REP(i, ma)arr[i]=-1;
		n*=2;
		string s;
		points= vii(n);
		choose=vector<bool>(n,false);
		REP(i, n){
			REP(j,n){
				dis[i][j]=-1;
			}
			cin>>s;
			cin>>points[i].fi>>points[i].se;
		}
		lim=(1<<n)-1;
		mi= calculate(0);
		
		counter++;
		printf("Case %d: %.2lf\n",counter,mi);
		
		
	}

    return 0;
}


