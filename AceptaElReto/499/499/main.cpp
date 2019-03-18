#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<pair<ii,ii>> vp;
vector<vector<int>> vi;
vector<vector<int>> vi2;
int main(){
    ios::sync_with_stdio(false);
    int f,c,n;
    int i,a,b,m;
    while(cin>>f>>c>>n&&f){
        vector<int> v;
        v.assign(c,0);
        vi.assign(f,v);
        vi2.assign(f,v);
        for(int j=0;j<n;++j){
            cin>>i>>a>>b>>m;
            vi2[a][i]+=m;
            if(b+1<f) vi2[b+1][i]-=m;
        }
        int suma=0;
        for(int j=0;j<c;j++){
            suma=0;
            for(int w=0;w<f;w++){
                suma+=vi2[w][j];
                vi[w][j]=suma;
            }
        }
        for(int j=0;j<f;j++){
            cout<<vi[j][0];
            for(int w=1;w<c;w++){
                cout<<" "<<vi[j][w];
            }
            cout<<"\n";
        }
    }
    
    return 0;
}
