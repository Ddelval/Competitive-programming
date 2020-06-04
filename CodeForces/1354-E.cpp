//  1354-E.cpp
//  Created by David del Val on 04/06/2020
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
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

inline pii operator + (pii a, pii b){
    return {a.fi+b.fi,a.se+b.se};
}
inline ostream& operator << (ostream& o, pii p){
    o<<p.fi<<" "<<p.se;
    return o;
}

template<typename>
struct is_std_vector : std::false_type {};

template<typename T, typename A>
struct is_std_vector<std::vector<T,A>> : std::true_type {};

template <typename T>
inline ostream& operator << (ostream& o, vector<T> &p){
    for(int i=0;i<p.size();++i){
        o<<setw(3)<<p[i];
        if(is_std_vector<T>::value)o<<"\n";
    }
    return o;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

struct component{
    vi el[2];
};

inline ostream& operator << (ostream& o, component& p){
    return o<<p.el[0]<<"\n"<<p.el[1]<<"\n--";
}

ll n,m;
vector<vector<int>> adyList;
vi visited;
bool bad=false;
ll a[3]={0,0,0};

void dfs(int i, int col,component& com){
    if(visited[i]&&visited[i]==col)bad=true;
    if(visited[i])return;

    col=!(col-1)+1;
    visited[i]=col;
    com.el[col==1].pb(i);

    for(auto con : adyList[i]) dfs(con,col,com);
    
}


#ifdef _LOCAL_
const int is=10;
#else
const int is=5002;
#endif

char knap[is][is];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    cin>>a[0]>>a[1]>>a[2];
    adyList=vector<vi>(n,vi());
    visited=vi(n);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adyList[a].pb(b);
        adyList[b].pb(a);

    }
    vector<component> components;
    for(int i=0;i<n;++i){
        component com;
        dfs(i,0,com);
        if(com.el[0].size()!=0 || com.el[1].size()!=0){
            components.push_back(com);
            //cout<<com<<"\n";
        }
    }
    if(bad){
        cout<<"NO\n";
        return 0;
    }
    int j1=components[0].el[0].size();
    int j2=components[0].el[1].size();
    knap[0][j1]=1;
    knap[0][j2]=-1;
    for(int i=1;i<components.size();++i){
        auto c= components[i];
        for(int j=0;j<=n;++j){
            if(knap[i-1][j]){
                if(j+c.el[0].size()<=n)knap[i][j+c.el[0].size()]=1;
                if(j+c.el[1].size()<=n)knap[i][j+c.el[1].size()]=-1;
            }
        }
    }
    
    //cout<<knap;

    if(knap[components.size()-1][a[1]])cout<<"YES\n";
    else{ 
        cout<<"NO\n";
        return 0;
    }
    vi labels(n);
    int j=a[1];
    int i=components.size()-1;
    int uc=0;
    while(i>=0){
        for (int a: components[i].el[knap[i][j]!=1]) labels[a]=2;
        for (int aa: components[i].el[knap[i][j]==1]){
            if(uc<a[0]){
                labels[aa]=1;
                uc++;
            }
            else{
                labels[aa]=3;
            }
        }
        if(i>0){
            j-=components[i].el[knap[i][j]!=1].size();
        }
        i--;

    }

    for(int i=0;i<n;++i){
        cout<<labels[i];
    }
    cout<<"\n";
    return 0;
}