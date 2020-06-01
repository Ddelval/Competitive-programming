//  D.cpp
//  Created by David del Val on 31/05/2020
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


int main(){
    
    int t;
    cin>>t;
    for(int w=0;w<t;++w){

        int n,k;
        cin>>n>>k;

        vector<unordered_set<int>> sets;

        for(int i=0;i<k;++i){
            int l,a;
            cin>>l;
            unordered_set<int> dat;
            for(int j=0;j<l;++j){
                cin>>a;
                dat.insert(a);
            }
            sets.pb(dat);
        }

        cout<<"? "<<n;
        for(int i=1;i<=n;++i){
            cout<<" "<<i;
        }
        cout<<"\n";
        cout.flush();
        int ma;
        cin>>ma;
        if(ma==-1)return 1;

        int r=1;
        int l=n;
        while(l>=r){
            int mid=(r+l)/2;
            cout<<"? "<<mid-r+1;
            for(int i=r;i<=mid;++i){
                cout<<" "<<i;
            }
            cout<<"\n";
            cout.flush();
            int nma;
            cin>>nma;
            if(nma==-1)return 1;
            if(nma<ma){
                r=mid+1;
            }
            else{
                l=mid-1;
            }
        }
        vi res;
        for(int i=0;i<k;++i){
            if(sets[i].count(r)){
                
                set<int> quest;
                for(int j=1;j<=n;++j){
                    if(sets[i].count(j))continue;
                    quest.insert(j);
                }
                cout<<"? "<<quest.size();
                for(int j:quest){
                    cout<<" "<<j;
                }
                cout<<"\n";
                cout.flush();
                int nma;
                cin>>nma;
                if(nma==-1)return 1;
                res.pb(nma);
            }
            else{
                res.pb(ma);
            }
        }
        cout<<"!";
        for(int i:res){
            cout<<" "<<i;
        }
        cout<<"\n";
        cout.flush();
        string resul;
        cin>>resul;
        if(resul=="Incorrect"){
            return 1;
        }

    }


    return 0;
}