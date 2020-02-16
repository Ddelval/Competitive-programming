// AceptaElReto 411:  Sobre la tela de una araña
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

int main() {
    ios::sync_with_stdio(false);
    long sop;
    long elef,out;
    bool b;
    while(cin>>sop&&sop){
        out=0;
        b=true;
        while(cin>>elef&&elef){
            sop-=elef;
            if(b&&sop>=0){
                out++;
            }
            else{
                b=false;
            }
        }
        cout<<out<<"\n";
    }
    return 0;
}

