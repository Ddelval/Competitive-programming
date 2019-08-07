// AceptaElReto 496:  La estación de esquí
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
int re;
int maxgain;
int tallowed;

struct Remon{
    int start, end;
    int cost, gain;
    Remon(int a,int b,int c){
        start=a;
        end=b;
        cost=c;
        gain=a-b;
        
    }
};
int finish;
vector<Remon> v;
bool flag;
void DFS(int cy,int ct,int skied){
    if(ct>tallowed) return;
    if(cy>=finish&&ct+(cy-finish)<=tallowed){
        flag=true;
        if(skied+(cy-finish)>maxgain){
            maxgain=skied+(cy-finish);
        }
    }
    for(int i=0;i<re;++i){
        if(v[i].start<=cy){
            DFS(v[i].end,ct+(cy-v[i].start)+v[i].cost,skied+(cy-v[i].start));
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    int a,b,c;
    int origin;
    while(cin>>re&&re){
        v.clear();
        for(int i=0;i<re;++i){
            cin>>a>>b>>c;
            v.push_back((Remon(a,b,c)));
        }
        cin>>origin>>finish>>tallowed;
        /*if(origin-finish>tallowed){
            cout<<"IMPOSIBLE\n";
            continue;
        }*/
        maxgain=0;
        flag=false;
        DFS(origin,0,0);
        if(!flag) cout<<"IMPOSIBLE\n";
        else cout<<maxgain<<"\n";
        
    }
    
    return 0;
}

