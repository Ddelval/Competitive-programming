// AceptaElReto 480:  ¿Cuántas pido?
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    int tot,bad,good;
    long out;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>tot>>bad>>good;
        out=(tot/good)*bad;
        if(tot%good){
            if(tot%good>=bad){
                out+=bad;
            }
            else{
                out+=tot%good;
            }
        }
        cout<<out<<"\n";
    }
    return 0;
}

