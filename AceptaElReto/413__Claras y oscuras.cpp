// AceptaElReto 413:  Claras y oscuras
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
    cin.tie(NULL);
    int cas;
    int b,n;
    int width,height;
    cin>>cas;
    for(int i=0;i<cas;++i){
        cin>>width>>height;
        b=ceil(width/2.0)*ceil(height/2.0)+floor(width/2.0)*floor(height/2.0);
        n=width*height-b;
        //if(n>b) swap(b,n);
        cout<<b<<" "<<n<<"\n";
    }
    return 0;
}

