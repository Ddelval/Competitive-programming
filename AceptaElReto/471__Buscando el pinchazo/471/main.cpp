// AceptaElReto 471:  Buscando el pinchazo
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
int mod(int a){
    if(a<0){
        a+=360;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    int pos,target;
    int dif1,dif2;
    for(int i=0;i<cas;++i){
        cin>>pos>>target;
        if(pos==target||abs(pos-target)==180){
            cout<<"DA IGUAL\n";
            continue;
        }
        dif1=mod(target-pos);
        dif2=mod(pos-target);
        if(dif1<dif2){
            cout<<"ASCENDENTE\n";
        }
        else{
            cout<<"DESCENDENTE\n";
        }
    }
    return 0;
}

