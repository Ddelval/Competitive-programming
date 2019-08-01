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
set<pair<int,int>> axis;
int main(){
    ios::sync_with_stdio(false);
    
    int cas;
    cin>>cas;
    while(cas--){
        axis.clear();
        int s;
        int a,b;
        cin>>s;
        for(int i=0;i<s;++i){
            cin>>a>>b;
            auto it = axis.find({a,b});
            if(it==axis.end()){
                axis.insert({a,b});
            }
            else{
                axis.erase(it);
            }
        }
        if(axis.size()){
            cout<<"Akash\n";
        }
        else{
            cout<<"Shivam\n";
        }
    }
    
    return 0;
}

