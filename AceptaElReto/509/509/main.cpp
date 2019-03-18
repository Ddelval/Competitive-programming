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
int board[105][105];
int width,height;
struct xy {
    int x, y;
    ll w;
    xy(int a, int b, ll c){
        x=a;
        y=b;
        w=c;
    }
};

ll cost[105][105];
ll mcos;
ll DFS(int x, int y){
    if(x==height) return INT_MAX;
    if(y==width) return INT_MAX;
    if(x==height-1&&y==width-1){
        return 0;
    }
    if(cost[x][y]!=INT_MAX) return cost[x][y];
    ll a=max(max((min(DFS(x+1,y),DFS(x,y+1))-board[x][y]),(ll)2-board[x][y]),(ll)2);
    return cost[x][y]=a;
    
}


int main(){
    ios::sync_with_stdio(false);
    while(cin>>width>>height){
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                cost[i][j]=INT_MAX;
            }
        }
        mcos=INT_MAX;
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                cin>>board[i][j];
            }
        }
        cout<<max(DFS(0, 0),(ll)2)<<"\n";
        
        
        
    }
    
    return 0;
}
