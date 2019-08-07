// AceptaElReto 289:  Lo que cuesta sumar
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
    int len;
    ll aux,aux2;
    ll totaleff;
    priority_queue<ll,deque<ll>,greater<ll>> pq;
    while(cin>>len&&len){
        while(!pq.empty()) pq.pop();
        for(int i=0;i<len;++i){
            cin>>aux;
            pq.push(aux);
        }
        totaleff=0;
        while(pq.size()>1){
            aux=pq.top(); pq.pop();
            aux2=pq.top(); pq.pop();
            pq.push(aux+aux2);
            totaleff+=aux+aux2;
        }
        cout<<totaleff<<"\n";
    }
    
    return 0;
}

