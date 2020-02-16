//10243
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int DP[1005][2];
vector<vi> adyList;

int calculate(int parent, bool picked, int node){
    if(DP[node][picked]!=-1)return DP[node][picked];
    int m=picked;
    if(!picked&&adyList[node].size()==0)m=1;
    for(auto a: adyList[node]){
        if(a==parent)continue;
        if(picked)m+=min(calculate(node,true,a),calculate(node,false,a));
        else m+=calculate(node,true,a);
    }
    //cout<<node<<" "<<picked<<" "<<m<<"\n";
    return DP[node][picked]=m;
}

int main(){
    int n;
    while(cin>>n&&n){
        adyList=vector<vi>(n+3,vi());
        int a,b;
        for(int i=0;i<=n+1;++i){
            DP[i][0]=DP[i][1]=-1;
        }
        for(int i=1;i<=n;++i){
            cin>>a;
            adyList[i]=vi(a);
            for(int j=0;j<a;++j)cin>>adyList[i][j];
        }
        int val=min(calculate(-1,true,1),calculate(-1,false,1));
        cout<<val<<"\n";
    }


    return 0;
}