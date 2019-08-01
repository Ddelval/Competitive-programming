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

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
bool use[10];
int diff(string build,string tar, int depth, int state){
    if(depth==tar.length()){
        int b=stoi(build);
        if(b>1000000) return INT_MAX/2;
        return abs(b-stoi(tar));
    }
    if(use[tar[depth]-'0']){
        return diff(build+(tar[depth]),tar,depth+1,0);
    }
    
    if(state==1){
        //We have to go low
        for(int i=0;i<10;++i){
            if(use[i]){
                return diff(build+(char)(i+'0'),tar,depth+1,1);
            }
        }
    }
    if(state==-1){
        for(int i=9;i>=0;--i){
            if(use[i]){
                return diff(build+(char)(i+'0'),tar,depth+1,-1);
            }
        }
        
        
    }
    
    int a,b;
    if(tar[depth]=='0'){
        //find the minimum that you can use
        for(int i=1;i<10;++i){
            if(use[i]){
                return diff(build+((char)(i+'0')),tar,depth+1,1);
            }
        }
    }
    if(tar[depth]=='9'){
        for(int i=9;i>=0;--i){
            if(use[i]){
                return diff(build+((char)(i+'0')),tar,depth+1,-1);
            }
        }
    }
    a=b=INT_MAX/2;
    //In this case explore both
    for(int i=tar[depth]-'0'+1;i<10;++i){
        if(use[i]){
            a= diff(build+((char)(i+'0')),tar,depth+1,1);
            break;
        }
    }
    
    for(int i=tar[depth]-'0'-1;i>=0;--i){
        if(use[i]){
            b= diff(build+((char)(i+'0')),tar,depth+1,-1);
            break;
        }
    }
    return min(a,b);
    
}




int main(){
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    while(cas--){
        for(int i=0;i<10;++i){
            cin>>use[i];
        }
        int q;
        cin>>q;
        string tar;
        int start;
        while(q--){
            cin>>start>>tar;
            int bu=diff("",tar,0,0)+1;
            int m=abs(stoi(tar)-start);
            cout<<min(bu,m)<<"\n";
        }
    }
    
    return 0;
}

