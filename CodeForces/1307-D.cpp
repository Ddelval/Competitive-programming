//  1307-D
//  Created by David del Val on 19/02/2020
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
#define REP(i,n) for(int i=0;i<n;i++)

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

#define msiz 200005

int ds[msiz];
int fs[msiz];
bool visited[msiz];


vector<vector<int>> adyList;
void bfs(int s,int* d){
    memset(d,INT_MAX/10,msiz);
    memset(visited,0,msiz);
    visited[s]=true;
    d[s]=0;
    queue<pii> q;
    q.push({s,0});
    while(!q.empty()){
        auto a=q.front(); q.pop();
        for(int p: adyList[a.fi]){
            if(!visited[p]){
                q.push({p,a.se+1});
                d[p]=a.se+1;
                visited[p]=true;
            }
        }
    }

}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    adyList=vector<vector<int>>(n+2,vi());
    vi special(k);
    for(int i=0;i<k;++i)cin>>special[i];
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        adyList[a].push_back(b);
        adyList[b].push_back(a);
    }

    bfs(1,ds);
    bfs(n,fs);
    int M=0;
    vector<pii> data;
    for(int i=0;i<k;++i){
        data.push_back({ds[special[i]]-fs[special[i]],special[i]});

    }
    sort(all(data));
    int sol=0;
    int premax=INT_MIN/10;
    for(auto el:data){
        //cout<<el.se<<" "<<sol<<"\n";
        sol=max(sol,fs[el.se]+premax);
        premax=max(premax,ds[el.se]);

    }
    cout<<min(sol+1,ds[n])<<"\n";



    return 0;
}