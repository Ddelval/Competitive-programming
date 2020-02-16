// AceptaElReto 183:  Anélidos
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
    int l;
    string s;
    string a,b;
    while(cin>>l){
        cin>>s;
        if(s=="C") break;
        s=s.substr(0,s.length()-1);
        for(int i=0;i<l;++i){
            a="";
            for(char el:s){
                if(el=='A') a+='N';
                else a+='A';
            }
            b="";
            for(int i=0;i<2*s.length();++i){
                if(i%2) b+=a[i/2];
                else b+=s[i/2];
            }
            s=b;
        }
        cout<<s<<"C\n";
    }
    
    return 0;
}
