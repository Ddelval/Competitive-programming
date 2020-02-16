// AceptaElReto 472:  Caminando voy
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
    int error,points;
    int cstart;
    int h,p;
    bool doable;
    while(cin>>error>>points){
        cin>>cstart;
        p=cstart;
        doable=true;
        for(int i=1;i<points;++i){
            cin>>h;
            if(h<=p&&doable){
                if(p-cstart>error){
                    doable=false;
                }
                cstart=h;
            }
            p=h;
        }
        if(p-cstart>error){
            doable=false;
        }
        if(doable){
            cout<<"APTA\n";
        }
        else{
            cout<<"NO APTA\n";
        }
    }
    return 0;
}

