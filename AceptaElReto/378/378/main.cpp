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
    int n,a,b;
    bool flag;
    vector<ii> v;
    while(cin>>n&&n){
        v.clear();
        for(int i=0;i<n;++i){
            cin>>a>>b;
            v.push_back(mp(a,b));
        }
        sort(v.begin(),v.end());
        int cmin;
        int cinvest;
        cmin=v[0].second;
        cinvest=v[0].first;
        flag=true;
        for(int i=1;i<v.size();++i){
            if(v[i].first==cinvest) cmin=v[i].second;
            else{
                if(v[i].second>cmin){
                    cmin=v[i].second;
                    cinvest=v[i].first;
                }
                else{
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout<<"SI\n";
        else cout<<"NO\n";
    }
    
    return 0;
}

