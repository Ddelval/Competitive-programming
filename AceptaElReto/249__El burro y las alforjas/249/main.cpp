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
int counter[20005];
int main(){
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    int b,s,a;
    while(cas--){
        for(int i=0;i<20005;++i){
            counter[i]=0;
        }
        cin>>b>>s;
        while(s--){
            cin>>a;
            counter[a]++;
        }
        a=0;
        for(int i=0;i<20005;++i){
            if(counter[i])a+=counter[i]/2;
            
        }
        cout<<min(a,b)<<"\n";
    }
    
    return 0;
}
