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
long coin[1000][1000];
int width,height;

int main(){
    ios::sync_with_stdio(false);
    int cas;
    ll suma;
    int value;
    cin>>cas;
    for(int i=0;i<cas;++i){
        int m,n;
        cin>>m>>n;
        if(n%2){
            suma=0;
            value=0;
            for(int j=0;j<m;++j){
                for(int k=0;k<n;++k){
                    cin>>value;
                    suma+=value;
                }
            }
        }
        else{
            suma=0;
            value=0;
            for(int j=0;j<m;++j){
                for(int k=0;k<n-1;++k){
                    cin>>value;
                    suma+=value;
                }
                cin>>value;
            }
            suma+=value;
        }
        cout<<suma<<"\n";
    }
    return 0;
}

