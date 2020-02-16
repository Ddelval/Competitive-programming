// AceptaElReto 451:  Huyendo de los zombis
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
#include <sstream>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
struct Stop{
    int line,wait;
    Stop(int i,int j){
        line=i;wait=j;
    }
};
int n,m;
vector<vector<Stop>> stops;
ll ady[105][105];
int mod(int a,int b){
    if(a-b>=0) return a-b;
    else return a-b+60;
}

ll mi;
void Warshall(){
    for(int k=0;k<m;++k){
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                if(ady[i][k]+ady[k][j]<ady[i][j]){
                    ady[i][j]=ady[i][k]+ady[k][j];
                }
            }
        }
    }
    mi=INT_MAX;
    for(auto st:stops[1]){
        for(auto en:stops[n]){
            mi=min(ady[st.line][en.line],mi);
        }
    }
}
int main(){
    int sstop;
    int t,index;
    stringstream in;
    string s;
    ios::sync_with_stdio(false);
    int nl;
    while(cin>>n>>m){
        vector<Stop> vi;
        int elap_t;
        stops.assign(n+2,vi);
        for(int i=0;i<m;++i){
            cin>>sstop;
            stops[sstop].push_back(Stop(i,0));
            getline(cin,s);
            in.clear();
            in.str(s);
            elap_t=0;
            while(in>>t>>index){
                elap_t+=t;
                stops[index].push_back(Stop(i,elap_t));
            }
            
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                ady[i][j]= INT_MAX;
            }
        }
        for(auto vec:stops){
            if(vec.size()>1){
                for(int i=0;i<vec.size();++i){
                    for(int j=0;j<vec.size();++j){
                        if(i!=j){
                            nl=mod(vec[i].wait,vec[j].wait);
                            if(nl<ady[vec[j].line][vec[i].line]){
                                ady[vec[j].line][vec[i].line]=nl;
                            }
                        }
                    }
                }
            }
        }
        Warshall();
        if(mi==INT_MAX) cout<<"Hoy no vuelvo\n";
        else cout<<mi<<"\n";
    }
    
    return 0;
}

