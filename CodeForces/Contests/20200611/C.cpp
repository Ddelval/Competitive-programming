//  C.cpp
//  Created by David del Val on 11/06/2020
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

int mat[31][31];
int mat2[31][31];
int diags[65];
int diags0[65];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        //cout<<"cas"<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>mat[n-1-i][j];
                //mat2[n-1-i][m-1-j]=mat[i][j];
            }
        }
        /*
        int diff=0;
        for(int i=0;i<int(ceil(m/2.0));++i){
            for(int j=0;j<=min(i,n-1);++j){
                cout<<j<<" "<<i<<"    "<<mat[j][i]<<" "<<mat2[j][i]<<endl;
                if(mat[j][i]!=mat2[j][i])diff++;
            }
        }
        cout<<diff<<"\n";
        */
       
        int x=n-1;
        int y=0;
        for(int i=0;i<n+m-1;++i){
            diags[i]=0;
            diags0[i]=0;
            if(i<m)x=n-1;
            else x=(n-1)-(i-m+1);
            if(i>=m)y=m-1;
            else y=i;

            //cout<<x<<" "<<y<<endl;
            while(x>=0 && y>=0){
                if(mat[x][y]==1)diags[i]++;
                else diags0[i]++;
                x--;
                y--;
            }
            
            //cout<<i<<"res"<<diags[i]<< " "<<diags0[i]<<endl;
        }
        //cout<<"\n\n\n";
        int counter=0;
        for(int i=0;i<(n+m-1)/2;++i){
            //cout<<i<<" "<<n+m-2-i<<endl;
            counter+=min(diags[i]+diags[n+m-2-i],diags0[i]+diags0[n+m-2-i]);
        }
        cout<<counter<<"\n";

    }
    return 0;
}