//spoj_101
#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,t;

int tim[50][50];
int money[50][50]; 

pii DP[50][1003];

// Returns cost and time needed to get to the end
pii go(int city, int tleft){
    if(tleft<0)return mp(INT_MAX/10, INT_MAX/10);
    if(city==n-1) return mp(0,0);
    if(DP[city][tleft].fi!=-1)return DP[city][tleft];


    pii ans=mp(INT_MAX,INT_MAX);

    for(int i=0;i<n;++i){
        if(i==city)continue;
        pii ret=go(i,tleft-tim[city][i]);
        if(ret.fi+money[city][i]<ans.fi){
            ans=ret;
            ans.fi+=money[city][i];
            ans.se+=tim[city][i];
        }
    }

    return DP[city][tleft]=ans;

}
int main(){

    while(cin>>n>>t&&(n||t)){
        for(int i=0;i<50;++i){
            for(int j=0;j<1003;++j) DP[i][j]=mp(-1,-1);
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>tim[i][j];
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>money[i][j];
            }
        }

        pii ans= go(0,t);
        cout<<ans.fi<<" "<<ans.se<<"\n";

    }

    return 0;
}