// AceptaElReto 304:  División euclídea
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
    int cas;
    ll d,D;
    ll c,r;
    cin>>cas;
    while(cas--){
        cin>>D>>d;
        if(!d){
            cout<<"DIV0\n";
            continue;
        }
        c=D/d;
        r=D%d;
        if(r<0){
            if(d<=0) c++;
            else c--;
            r=D-c*d;
        }
        
        cout<<c<<" "<<r<<"\n";
        
        
        
    }
}

