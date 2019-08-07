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
#include <sstream>
#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    string s;
    int cas;
    ll sum;
    int arg1;
    char ar;
    cin>>cas;
    bool b;
    while(cas--){
        cin>>sum;
        b=false;
        while(cin>>ar &&ar!='.'){
            cin>>arg1;
            if(ar=='+') sum+=arg1;
            else sum-=arg1;
            
            if(b)cout<<", ";
            else b=true;
            cout<<sum;
        }
        cout<<"\n";
    }
    return 0;
}

