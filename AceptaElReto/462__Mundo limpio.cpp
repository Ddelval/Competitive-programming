// AceptaElReto 462:  Mundo limpio
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
    long long t;
    long long h,m,s,d;
    int mult;
    scanf("%d",&cas);
    for(int i=0;i<cas;++i){
        scanf("%d",&mult);
        scanf("%lld:%lld:%lld",&h,&m,&s);
        t=h*3600+m*60+s;
        t*=mult;
        s=t%60;
        m=t/60;
        h=m/60;
        d=h/24;
        h%=24;
        m%=60;
        printf("%lld %.2lld:%.2lld:%.2lld\n",d,h,m,s);
    }
    return 0;
}

