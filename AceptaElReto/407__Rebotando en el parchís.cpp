// AceptaElReto 407:  Rebotando en el parchís
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
int p,t,c;
int mod(){
    int a=p+t;
    if(a<=c){
        return a;
    }
    else{
        return 2*c-a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    while(cin>>c>>p>>t&&(c||p||t)){
        cout<<mod()<<"\n";
    }
    return 0;
}

