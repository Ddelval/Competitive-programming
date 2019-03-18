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
 long data[1000009];
int main(){
    ios::sync_with_stdio(false);
    int mol,consul;
    int s,e;
    long aux;
    long sum;
    while(cin>>mol&&mol){
        sum=0;
        for(int i=0;i<mol;++i){
            cin>>aux;
            sum+=aux;
            data[i]=sum;
        }
        cin>>consul;
        for(int i=0;i<consul;i++){
            cin>>s>>e;
            e--;
            s--; s--;
            
            if(s<0) cout<<data[e]<<"\n";
            else   cout<<data[e]-data[s]<<"\n";
        }
    }
    
    return 0;
}

