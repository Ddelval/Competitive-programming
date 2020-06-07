//  D.cpp
//  Created by David del Val on 07/06/2020
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
const int siz=51;
char board[siz][siz];
int n,m;

bool isblockable(int i,int j){
    if(i<0 || i>=n)return true;
    if(j<0 || j>=m)return true;
    if(board[i][j]!='G'){
        if(board[i][j]!='B')board[i][j]='#';
        return true;
    }
    
    return false;

}
bool blockBad(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j]=='B'){
                if(!isblockable(i,j-1)){
                    return false;
                }
                if(!isblockable(i-1,j)){
                    return false;
                }
                if(!isblockable(i,j+1)){
                    return false;
                }
                if(!isblockable(i+1,j)){
                    return false;
                }

            }
        }
    }
    return true;
}

bool visited[siz][siz];
ll dfs(int i, int j){
    if(i<0||i>=n)return 0;
    if(j<0||j>=m)return 0;
    if(board[i][j]=='#')return 0;
    if(visited[i][j])return 0;
    visited[i][j]=true;
    ll counter=0;
    if(board[i][j]=='G')counter+=1;
    if(board[i][j]=='B')counter+=INT_MIN;

    return counter+dfs(i-1,j)+dfs(i,j-1)+dfs(i,j+1)+dfs(i+1,j);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int cgood=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>board[i][j];
                if(board[i][j]=='G')cgood++;
                visited[i][j]=0;
            }
        }
        bool b= blockBad();
        //cout<<b<<endl;
        int found= dfs(n-1,m-1);
        /*cout<<"found: "<<found<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }*/
        if(!b ||found!=cgood){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }

    }
    
    return 0;
}