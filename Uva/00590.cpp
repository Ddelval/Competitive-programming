//00590
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;


vi costs[11][11];
int N,K;
// n to m in the k-th day
int calculate(int k, int n, int m){
    k--;
    return costs[n][m][k%costs[n][m].size()]? costs[n][m][k%costs[n][m].size()]: INT_MAX;
}

ll DP[1001][10];
ll explore(){
    for(int k=0;k<=K;++k){
        for(int n=0;n<N;++n)DP[k][n]=-1;
    }
    DP[0][0]=0;

    for(int k=1;k<=K;++k){
        for(int n=0;n<N;++n){
            DP[k][n]=INT_MAX;
            for(int m=0;m<N;++m){
                if(m==n)continue;
                if(DP[k-1][m]==-1)continue;
                DP[k][n]=min(DP[k][n],DP[k-1][m]+calculate(k,m,n));
            }
            if(DP[k][n]==INT_MAX)DP[k][n]=-1;
        }
    }
    
    return DP[K][N-1];
}
int main(){
    int cnt=1;
    while(cin>>N>>K&&(N||K)){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(j==i)continue;                
                int l;
                cin>>l;
                costs[i][j]=vi(l);
                for(int w=0;w<l;++w)cin>>costs[i][j][w];
            }
        }

        ll ans=explore();
        cout<<"Scenario #"<<cnt<<"\n";
        if(ans==-1){
            cout<<"No flight possible.\n";
        }
        else{
            cout<<"The best flight costs "<<ans<<".\n";
        }
        cout<<"\n";

    cnt++;
    }


    return 0;
}