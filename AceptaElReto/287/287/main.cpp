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
    int i;
    ll iprize, ndays;
    ll target;
    ll guests;
    ll box;
    while(cin>>iprize>>ndays){
        box=0;
        if(!ndays){
            cout<<"0\n";
            continue;
        }
        else if(ndays==1){
            cin>>guests;
            box=guests*iprize;
            box%=78787;
            cout<<box<<"\n";
            continue;
        }
        else if(ndays==2){
            cin>>guests;
            box+=guests*iprize;
            cin>>guests;
            box+=guests*iprize;
            box%=78787;
            cout<<box<<"\n";
            continue;
        }
        else if(ndays%2){
            //Odd days
            target= ndays/2+1;
            //When we exceed that arget, we go down in prize;
            for(i=0;i<target;++i){
                cin>>guests;
                box+=iprize*guests;
                iprize*=3;
                iprize%=78787;
                box%=78787;
            }
            iprize*=-26262; //Modular arithmetics
            iprize%=78787;
            iprize+=78787;
            iprize%=78787;
            for(;i<ndays;++i){
                cin>>guests;
                iprize*=-26262;
                iprize%=78787;
                iprize+=78787;
                iprize%=78787;
                box+=iprize*guests;
                
                box%=78787;
            }
        }
        else{
            //Even days
            target= ndays/2;
            //When we exceed that arget, we go down in prize;
            for(i=0;i<target;++i){
                cin>>guests;
                box+=iprize*guests;
                iprize*=3;
                iprize%=78787;
                box%=78787;
            }
            iprize*=-26262;
            iprize%=78787;
            iprize+=78787;
            iprize%=78787;
            i++;
            cin>>guests;
            box+=iprize*guests;
            
            for(;i<ndays;++i){
                cin>>guests;
                iprize*=-26262;
                iprize%=78787;
                iprize+=78787;
                iprize%=78787;
                box+=iprize*guests;
                
                box%=78787;
            }
        }
        cout<<box<<"\n";
    }
    
    return 0;
}

