// AceptaElReto 382:  Internet en el metro
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
#define mp(x,y) make_pair(x,y)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int cas;
    long ltun;
    long n_ant;
    long pos,rad;
    long ant_b, ant_e;
    long prev_e;
    cin>>cas;
    for(int z=0;z<cas;++z){
        cin>>ltun>>n_ant;
        prev_e=0;
        for(int i=0;i<n_ant;++i){
            cin>>pos>>rad;
                ant_b=pos-rad;
                ant_e=pos+rad;
                if(ant_b<=prev_e) prev_e=max(ant_e,prev_e);
        }
            if(prev_e<ltun) cout<<"NO\n";
            else cout<<"SI\n";
    
    }
    return 0;
}

