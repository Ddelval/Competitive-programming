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
    cin.tie(NULL);
    ll suma;
    int aux;
    int index;
    while(cin>>aux&&aux){
        index=suma=0;
        while(aux){
            index++;
            suma+=aux;
            cin>>aux;
            
        }
        if(suma%index){
            cout<<"IMPOSIBLE\n";
        }
        else{
            cout<<"REPARTO JUSTO\n";
        }
    }
    
    return 0;
}

