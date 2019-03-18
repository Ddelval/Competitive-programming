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
    int n;
    bool a=false,e=false,i=false,o=false,u=false;
    string s;
    cin>>n>>s;
    for(char c:s){
        if(c=='a') a=true;
        else if(c=='e') e=true;
        else if(c=='i') i=true;
        else if(c=='o') o=true;
        else if(c=='u') u=true;
    }
    if(a+e+i+o+u>=4){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    
    return 0;
}

