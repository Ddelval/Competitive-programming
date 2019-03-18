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
#include <string.h>
#include <limits.h>
#include <fstream>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
/*
 First element stores the cost and second edge the element
 */
int costofsend[1000];
int mat[100][100];
int minimum;
void explore(int nn,int accumcost){
    if(accumcost>minimum) return;
    if(accumcost+costofsend[nn]<minimum){
        minimum=accumcost+costofsend[nn];
    }
    for(int i=0;i<100;++i){
        if(mat[nn][i]!=-1){
            explore(i,accumcost+mat[nn][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    ifstream in("/Users/daviddelval/Desktop/In.txt");
    ofstream out("/Users/daviddelval/Desktop/Out.txt");
    int cas,N,V,parties;
    int a,b,c;
    string sin;
    in>>cas;
    for(int i=1;i<=cas;++i){
        for(int i=0;i<1000;++i){
            costofsend[i]=0;
        }
        for(int i=0;i<100;++i){
            for(int j=0;j<100;++j){
                mat[i][j]= -1;
            }
        }
        in>>N>>V>>parties;
        for(int i=0;i<N;++i){
            in>>costofsend[i];
        }
        for(int i=0;i<V;++i){
            in>>a>>b>>c;
            mat[a][b]=c;
            mat[b][a]=c;
        }
        minimum=costofsend[i];
        explore(0,0);
        cout<<"Case #"<<i<<": "<<minimum;
        
        
    }
    
    
    
}
