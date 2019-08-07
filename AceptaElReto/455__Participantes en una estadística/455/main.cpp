// AceptaElReto 455:  Participantes en una estadística
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
int c;
int mcd(int a,int b){
    c=a%b;
    if(c) return mcd(b,c);
    else return b;
}
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int mc;
    cin>>cas;
    for(int i=0;i<cas;i++){
        cin>>mc;
        mc=mcd(10000,mc);
        cout<<(10000/mc)<<"\n";
    }
    return 0;
}

