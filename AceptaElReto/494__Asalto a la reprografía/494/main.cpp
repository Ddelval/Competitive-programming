// AceptaElReto 494:  Asalto a la reprografía
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
int times[1000];
int dat;

int main(){
    ios::sync_with_stdio(false);
    int prev,curr;
    int sindex,cfind,eseq;
    int st,j;
    while(cin>>dat&&dat){
        cin>>prev;
        for(int i=1;i<dat;++i){
            cin>>curr;
            times[i-1]=curr-prev;
            prev=curr;
        }
        st=times[0];
        sindex=0;
        eseq=dat-2;
        for(int i=1;i<dat-1;i++){
            if(times[i]==st){
                for(j=i+1;j<dat-1;++j){
                    //if(sindex+j-1>j) break;
                    if(times[j]!=times[sindex+j-i]){
                        eseq=i;
                        break;
                    }
                    
                }
                if(j==dat-1){
                    eseq=i;
                    break;
                }
            }
        }
        //int n=findLongestRepeatingSubSeq();
        cout<<prev+times[(dat-1)%(eseq)]<<"\n";
    }
    
    return 0;
}

