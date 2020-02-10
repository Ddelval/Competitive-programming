//10702
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
typedef long long ll;

ll DP[101][1001];
int c,s,e,t;
int ady[101][101];
set<int> endss;
ll calculate(int c_city, int moves_left){
    if(DP[c_city][moves_left]!=-2)return DP[c_city][moves_left];
    if(moves_left==0){
        if(endss.count(c_city))return DP[c_city][moves_left]=0;
        else return DP[c_city][moves_left]=-1;
    }
    ll ma = -1;
    ll aux;
    for(int i=0;i<c;++i){
        if(i==c_city)continue;
        aux=calculate(i,moves_left-1);
        if(aux==-1)continue;
        ma=max(ma,aux+ady[c_city][i]);
    }
    return DP[c_city][moves_left]=ma;
}


int main(){
    
    while(cin>>c>>s>>e>>t&&(c||s||e||t)){
        endss.clear();
        for(int i=0;i<101;++i)for(int j=0;j<1001;++j){
            DP[i][j]=-2;
        }
        for(int i=0;i<c;++i)for(int j=0;j<c;++j){
            cin>>ady[i][j];
        }
        s--;
        int a;
        for(int i=0;i<e;++i){
            cin>>a;
            endss.insert(a-1);
        }
        cout<<calculate(s,t)<<"\n";



    }


    return 0;
}

