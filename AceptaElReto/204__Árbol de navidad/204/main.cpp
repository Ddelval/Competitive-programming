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
string in;
bool ok;
int cursor;

int explore(){
    int c1,c2;
    cursor++;
    if(in[cursor]=='Y'){
        c1=explore();
        if(!ok){
            return 0;
        }
        c2=explore();
        if(abs(c1-c2)>1){
            ok=false;
        }
        return c1+c2;
    }
    else if(in[cursor]=='.'){
        return 0;
    }
    else{
        return 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    while(getline(cin,in)){
        ok=true;
        cursor=-1;
        explore();
        cout<<(ok? "OK\n":"KO\n");
    }
    return 0;
}

