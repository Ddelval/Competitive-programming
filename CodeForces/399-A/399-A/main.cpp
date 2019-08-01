/***********
 CodeForces 399-A
 @author  David del Val
*/

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

int main(){
    ios::sync_with_stdio(false);
    int n,k,p;
    while(cin>>n>>p>>k){
        if(p<1||p>n) continue;
        if(p-k>1) cout<<"<< ";
        for(int i=p-k;i<p;++i){
            if(i<=0){i=0; continue;}
            cout<<i<<" ";
        }
        cout<<"("<<p<<")";
        for(int i=p+1;i<=p+k;++i){
            if(i>n) break;
            cout<<" "<<i;
        }
        if(p+k<n) cout<<" >>";
        cout<<"\n";
        
        
    }
    
    return 0;
}

