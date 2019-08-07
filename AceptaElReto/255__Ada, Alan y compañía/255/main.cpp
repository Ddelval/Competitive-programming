#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
string s;
int board [10];
int checkPalin(int length){
    int wlength=s.length();
    bool works;
    if(length%2){
        //Odd length
        for(int i=length/2;i<=wlength-length/2;++i){
            works=true;
            for(int j=1;j<=length/2&&works;++j){
                if(s[i-j]!=s[i+j]){
                    works=false;
                }
            }
            if(works){
                return true;
            }
        }
    }
    else{
        for(int i=length/2-1;i<=wlength-length/2;++i){
            works=true;
            for(int j=0;j<length/2&&works;++j){
                if(s[i-j]!=s[i+j+1]){
                    works=false;
                }
            }
            if(works){
                return true;
            }
        }
    }
    
    return false;
}
int busbin(int x1,int x2){
    if(x1+1==x2){
        return x1;
    }
    int a=(x1+x2)/2;
    if(checkPalin(a)||checkPalin(a+1)){
        return busbin(a,x2);
    }
    else{
        return busbin(x1,(x1+x2)/2);
    }
}
int main() {
    ios::sync_with_stdio(false);
    while(getline(cin,s)){
        if(!checkPalin(s.length())){
            cout<<busbin(1,s.length())<<"\n";
        }
        else{
            cout<<s.length()<<"\n";
        }
        
    }
    return 0;
}

