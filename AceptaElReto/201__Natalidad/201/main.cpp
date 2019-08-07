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
bool only1;
bool all2;
string s;
int cursor;
int createtree(){
    int children;
    cursor++;
    if(s[cursor]=='.'){
        return 0;
    }
    else{
        children=createtree()+createtree();
        if(children==2){
            only1=false;
        }
        if(children==1)
            all2=false;
        return 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    
    while(getline(cin,s)){
        if(s=="."){
            break;
            
        }
        cursor=-1;
        only1=true;
        all2=true;
        createtree();
        if(only1){
            cout<<"1";
        }
        if(all2){
            cout<<"2";
        }
        if(!all2&&!only1){
            cout<<"N";
        }
        cout<<"\n";
        
    }
    return 0;
}

