//  1345-D.cpp
//  Created by David del Val on 08/06/2020
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

const int lim=1000;
ll n,m;
int col[lim];
int row[lim];
char board[lim][lim];
int visited[lim][lim];

void bfs(int i, int j){
    if(i<0||i>=n)return;
    if(j<0||j>=m)return;
    if(board[i][j]=='.')return;
    if(visited[i][j])return;
    visited[i][j]=1;
    
    bfs(i-1,j);
    bfs(i,j-1);
    bfs(i+1,j);
    bfs(i,j+1);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    
    int blankrows=0;
    int blankcols=0;
    int components=0;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            if(board[i][j]=='#'){
                if(!row[i])row[i]=1;
                if(!col[j])col[j]=1;
                
                if(row[i]==2)goto NO;
                if(col[j]==2)goto NO;
            }
            else{
                if(row[i])row[i]=2;
                if(col[j])col[j]=2;
            }
            
        }
    }
    for(int i=0;i<n;++i)blankrows+=row[i]==0;
    for(int j=0;j<m;++j)blankcols+=col[j]==0;
    
    if(blankcols*blankrows==0 && blankcols+blankrows!=0)goto NO;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j]=='#' && !visited[i][j]){
                components++;
                bfs(i,j);
            }
        }
    }
    cout<<components<<"\n";
    
    
    return 0;
    
    NO:
    cout<<"-1\n";
    return 0;
}