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
int main() {
    ios::sync_with_stdio(false);
    ll suma;
    ifstream in("/Users/daviddelval/Desktop/In.txt");
    ofstream out("/Users/daviddelval/Desktop/Out.txt");
    int cas,len,aux;
    in>>cas;
    for(int i=1;i<=cas;++i){
        in>>len;
        suma=0;
        for(int j=0;j<len;++j){
            in>>aux;
            if(aux>0){
                suma+=aux;
            }
        }
        out<<"Case #"<<i<<": "<<suma<<"\n";
    }
    
    
    
}
