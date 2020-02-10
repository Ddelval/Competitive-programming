//10681
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

bool explored[100][210];
bool ady[100][100];
int cc,l,de;
void explore(int c, int d){
    if(d>de)return;
    if(explored[c][d])return;
    explored[c][d]=true;
    for(int i=0;i<cc;++i){
        if(ady[c][i]){
            explore(i,d+1);
        }
    }

}
int main(){
    while(cin>>cc>>l&&(l||cc)){
        for(int i=0;i<cc;++i){
            for(int j=0;j<cc;++j){
                ady[i][j]=0;
            }
        }
        int a,b;
        for(int i=0;i<l;++i){
            cin>>a>>b;
            a--;
            b--;
            ady[a][b]=1;
            ady[b][a]=1;
        }
        
        int s,e;
        cin>>s>>e>>de;

        for(int i=0;i<cc;++i){
            for(int j=0;j<=de;++j){
                explored[i][j]=false;
            }
        }
        explore(s-1,0);
        if(explored[e-1][de])cout<<"Yes, Teobaldo can travel.\n";
        else cout<<"No, Teobaldo can not travel.\n";
    }


    return 0;
}