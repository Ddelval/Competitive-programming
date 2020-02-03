//  D
//	main.cpp
//  Created by David del Val on 01/11/2019
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
int parent[2000];
int rankk [2000];
int hpow  [2000];
int find(int i){
    while(parent[i]!=parent[parent[i]]){
        parent[i]=parent[parent[i]];
    }
    return parent[i];
}
void Union(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rankk[x]>rankk[y]){
        parent[y]=parent[x];
    }
    else if(rankk[x]<rankk[y]){
        parent[x]=parent[y];
    }
    else{
        rankk[x]++;
        parent[y]=parent[x];
    }
    hpow[x]|=hpow[y];
    hpow[y]|=hpow[x];
}

void start(int n){
    REP(i, n){
        parent[i]=i;
        rankk[i]=1;
        hpow[i]=0;
    }
}
vi psbuilt;
ll ncon=0;
vii con;

ll krus(vector<pair<ll,pii>> &pq){
    ll cos=0;
    for(int i=0;i<pq.size();++i){
        int p1,p2;
        p1=find(pq[i].se.fi);
        if(pq[i].se.se==-1){
            if(hpow[p1]==0){
                hpow[p1]=1;
                psbuilt.pb(pq[i].se.fi);
                cos+=pq[i].fi;
            }
            continue;
        }
        
        p2=find(pq[i].se.se);
        if(p1==p2||(hpow[p1]&&hpow[p2]))continue;
        ncon++;
        con.pb(mp(pq[i].se.fi,pq[i].se.se));
        cos+=pq[i].fi;
        Union(p1,p2);
    }
    
    return cos;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    start(n);
    vii coords=vii(n);
    REP(i,n)cin>>coords[i].fi>>coords[i].se;
    vi pow=vi(n);
    REP(i,n)cin>>pow[i];
    vl karr=vl(n);
    REP(i,n)cin>>karr[i];
    vector<pair<ll,pii>> vvs;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            vvs.pb({(karr[i]+karr[j])*(abs(coords[i].fi-coords[j].fi)+abs(coords[i].se-coords[j].se)),mp(i,j)});
        }
    }
    for(int i=0;i<n;++i){
        vvs.pb(mp(pow[i],mp(i,-1)));
    }
    sort(all(vvs));
    ll cs=krus(vvs);
    cout<<cs<<"\n";
    cout<<psbuilt.size()<<"\n";
    for(int i=0;i<psbuilt.size();++i){
        if(i)cout<<" ";
        cout<<psbuilt[i]+1;
    }
    cout<<"\n";
    cout<<ncon<<"\n";
    for(int i=0;i<con.size();++i){
        cout<<con[i].fi+1<<" "<<con[i].se+1<<"\n";
    }
    

    return 0;
}


