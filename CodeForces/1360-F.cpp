//  1360-F.cpp
//  Created by David del Val on 21/06/2020
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
template <typename T, typename R>
inline ostream& operator << (ostream& o, pair<T,R> p){
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

int n,m;
map<char,vector<int>> ma[10];
char res[10];
bool explore(int index, set<int>& discarded){
   /*for(int i=0;i<index;++i)cout<<res[i];
   cout<<endl;
   for(auto a:discarded)cout<<a<<" ";
   cout<<endl<<endl;*/
   if(index>=m && discarded.size()<=n)return true; 
   if(discarded.size()>n){
       //cout<<res<<endl;
       return false;
   }

    for(auto a:ma[index]){
        res[index]=a.fi;
        set<int> s=discarded;
        for(auto b:a.se){
            if(s.count(b)){
                //cout<<res<<endl;
                goto EN;
            }
            s.insert(b);
        }
        if(explore(index+1,s))return true;
        EN:
       res[index]=a.fi; 
    }
    return false;

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vi in;
        for(int i=0;i<n;++i)in.pb(i);
        for(int i=0;i<10;++i){
            ma[i].clear();
        }
        vector<string> data;
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            data.pb(s);
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(ma[j].find(data[i][j])==ma[j].end()){
                    ma[j][data[i][j]]=in;
                }
                auto it=find(all(ma[j][data[i][j]]),i);
                if(it!=ma[j][data[i][j]].end()){
                    ma[j][data[i][j]].erase(it);
                }
            }
        }
        /*for(int i=0;i<m;++i){
            for(auto a:ma[i]){
                cout<<a<<endl;
            }
            cout<<endl;
        }*/
        set<int> s;
        if(explore(0,s)){
            for(int i=0;i<m;++i)cout<<res[i];
            cout<<"\n";
        }
        else{
            cout<<"-1\n";
        }
        

    }
    
    return 0;
}