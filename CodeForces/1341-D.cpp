//  1341-D.cpp
//  Created by David del Val on 18/06/2020
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
using uint=unsigned int;

const uint limd=1<<7;

vector<pii> convert[limd];
uint num[]={
    0b1110111u, 0b0010010u, 0b1011101u, 0b1011011u, 0b0111010u, 0b1101011u,
    0b1101111u, 0b1010010u, 0b1111111u, 0b1111011u
};

void fill(){
    for(int i=0;i<limd;++i){
        for(int j=0;j<10;++j){
            if(i-(num[j]&i)!=0){
                
            }
            else{
                uint r=num[j]-(num[j]&i);
                int count=0;
                for(int w=0;w<10;++w){
                    if(r&(1Ul<<w))count++;
                }
                convert[i].pb({count,j});
            }
        }
    }
}
const int limn=2000+10;
const int limk=2000+10;
int dp[limn][limk];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    fill();
    int n,k;
    cin>>n>>k;
    vector<uint> ve(n);
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        ve[n-i-1]=(stol(s,NULL,2));
    }
    
    //cout<<"con"<<convert[0]<<endl;
    for(auto a: convert[ve[0]]){
        if(k-a.fi>=0)dp[0][k-a.fi]=a.se+1;
    }

    for(int i=1;i<n;++i){
        for(int j=0;j<=k;++j){ 
            if(!dp[i-1][j])continue;
            
            for(auto a:convert[ve[i]]){
                
               if(j-a.fi>=0)dp[i][j-a.fi]=max(dp[i][j-a.fi],a.se+1); 
            }
            
        }
    }
    vi digits;
    int pointer=0;
    if(dp[n-1][0]==0){
        cout<<"-1\n";
        goto END;
    }
   
    
    for(int i=n-1;i>=0;--i){
        int res=dp[i][pointer]-1;
        digits.pb(res);
        
        uint r=num[res]-(num[res]&ve[i]);
        int count=0;
        for(int w=0;w<10;++w){
            if(r&(1Ul<<w))pointer++;
        }
    }
    for(auto a: digits)cout<<a;
    cout<<"\n";
END:
    return 0;
    for(int i=0;i<11;++i){
        for(int j=0;j<11;++j)
        cout<<setw(3)<<dp[i][j]-1<<" ";
        cout<<endl;
    }
    
    
    
    return 0;
}