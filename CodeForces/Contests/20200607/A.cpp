//  A.cpp
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

int matrix[55][55];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vi rows(n,0);
        vi cols(m,0);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>matrix[i][j];
                if(matrix[i][j]){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        int lib_rows=n-accumulate(all(rows),0);
        int lib_cols=m-accumulate(all(cols),0);
        if(min(lib_cols,lib_rows)%2==0){
            cout<<"Vivek\n";
        }
        else{
            cout<<"Ashish\n";
        }


    }
    
    return 0;
}