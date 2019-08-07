// AceptaElReto 456:  Tarta Sacher
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
    int cas;
    int dim,ret;
    int a,b,target;
    cin>>cas;
    for(int i=0;i<cas;i++){
        cin>>a>>b>>target;
        dim=a*b;
        ret=target/dim;
        if(target%dim){
            ret++;
        }
        cout<<ret<<"\n";
    }
    return 0;
}

