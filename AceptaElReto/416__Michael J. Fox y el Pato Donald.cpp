// AceptaElReto 416:  Michael J. Fox y el Pato Donald
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
bool found[13][32];
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int d,m;
    bool done;
    while(scanf("%d",&cas)&&cas){
        done=false;
        for(int i=1;i<13;++i){
            for(int j=1;j<32;++j){
                found[i][j]=false;
            }
        }
        for(int i=0;i<cas;++i){
            scanf("%d/%d/%*d",&d,&m);
            if(!done){
                if(found[m][d]) done=true;
                else found[m][d]=true;
            }
            
        }
        if(done) cout<<"SI\n";
        else cout<<"NO\n";
        
        
    }
    return 0;
}

