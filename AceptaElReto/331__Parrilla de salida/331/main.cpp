// AceptaElReto 331:  Parrilla de salida
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
typedef pair<ll,string> driver;
vector<driver> rac;
bool tae [28];
int main(){
    ios::sync_with_stdio(false);
    int num;
    int npos;
    bool flag;
    while(cin>>num&&num){
        int pos;
        for(int i=0;i<28;++i){
            tae[i]=false;
        }
        string name;
        flag = false;
        rac.clear();
        for(int i=1;i<=num;++i){
            cin>>pos;
            getline(cin,name);
            npos=i+pos;
            if(flag||npos<1||npos>26||tae[npos]){
                flag=true;
                continue;
            }
            tae[npos]=true;
            rac.push_back(mp(npos,name));
        }
        if(flag){
            cout<<"IMPOSIBLE\n-----\n";
            continue;
        }
        sort(rac.begin(),rac.end());
        for(auto el:rac){
            cout<<el.first<<el.second<<"\n";
        }
        cout<<"-----\n";
        
        
    }
    
    return 0;
}
