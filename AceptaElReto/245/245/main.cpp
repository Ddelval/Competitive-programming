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
    int longit;
    ll prev,prev2, curr;
    bool flag;
    while(cin>>longit&&longit){
        cin>>prev;
        cin>>prev2;
        flag=false;
        if(prev<prev2){
            prev=prev2;
            for(int i=2;i<longit;++i){
                cin>>curr;
                
                if(prev>=curr){
                    flag= true;
                }
                else{
                    prev=curr;
                }
            }
        }
        else if(prev>prev2){
            prev=prev2;
            for(int i=2;i<longit;++i){
                cin>>curr;
                
                if(prev<=curr){
                    flag= true;
                }
                else{
                    prev=curr;
                }
            }
        }
        else{
            flag=true;
            for(int i=2;i<longit;++i){
                cin>>curr;
            }
        }
       
        if(flag){
            cout<<"DESCONOCIDOS\n";
        }
        else cout<<"DALTON\n";
    }
    
    return 0;
}

