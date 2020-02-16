// AceptaElReto 383:  El alcance de las historias
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <limits.h>
#include <queue>
#define mp(x,y) make_pair(x,y)
using namespace std;
long ma,mi;
long fin;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int length,pag;
    cin>>cas;
    for(int z=0;z<cas;++z){
        cin>>length;
        cin>>ma>>mi;
        fin=ma-mi;
        if(mi>ma){
            ma=mi;
            mi=INT_MAX;
        }
        for(int i=2;i<length;++i){
            cin>>pag;
            if(pag>ma){
                if(ma-pag>fin) fin=ma-pag;
                //else if (mi!=INT_MAX&&mi-pag>fin) fin=mi-pag;
                ma=pag;
                mi=INT_MAX;
                continue;
            }
            if(pag<mi){
                mi=pag;
                if(ma-mi>fin) fin=ma-mi;
                continue;
            }
            
        }
        cout<<fin<<"\n";
        
    }
    return 0;
}

