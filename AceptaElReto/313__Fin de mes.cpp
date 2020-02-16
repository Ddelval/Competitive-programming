// AceptaElReto 313:  Fin de mes
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int cas;
    int prev,bal;
    cin>>cas;
    for(int i=0;i<cas;++i){
        cin>>prev>>bal;
        if((prev+bal)>=0){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}

