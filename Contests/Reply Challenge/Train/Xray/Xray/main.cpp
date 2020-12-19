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
#include <string.h>
#include <limits.h>
#include <fstream>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int rad[1005];
int len;
int simpas(){
    int cindex=0;
    int out=0;
    int cp;
    while(cindex<len){
        
        while(rad[cindex]){
            cp=cindex;
            while(rad[cp]&&cp<len){
                rad[cp]--;
                cp++;
            }
            out++;
        }
        cindex++;
    }
    return out;
}
int main() {
    ios::sync_with_stdio(false);
    ifstream in("/Users/daviddelval/Desktop/In.txt");
    ofstream out("/Users/daviddelval/Desktop/Out.txt");
    int cas;
    in>>cas;
    for(int i=1;i<=cas;++i){
        in>>len;
        for(int j=0;j<len;++j){
            in>>rad[j];
        }
        out<<"Case #"<<i<<": "<<simpas()<<"\n";
    }
    return 0;

}
