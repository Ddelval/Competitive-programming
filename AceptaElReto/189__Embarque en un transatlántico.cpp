// AceptaElReto 189:  Embarque en un transatlántico
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
    vector <int> q;
    string s;
    int pas,index;
    int aux;
    vector<int>::iterator size;
    while(cin>>pas&&pas){
        q.clear();
        for(int i=0;i<pas;++i){
            cin>>aux;
            q.push_back(aux);
        }
        int consul;
        cin>>consul;
        size=q.end();
        for(int i=0;i<consul;++i){
            cin>>s>>index;
            if(s=="CONSULTA"){
                index--;
                cout<<q[index]<<"\n";
            }
            else{
                size=remove(q.begin(),size,index);
                cout<<size-q.begin()<<"\n";
            }
            
        }
        cout<<"*\n";
    }
    
    return 0;
}
