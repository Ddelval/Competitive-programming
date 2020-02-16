// AceptaElReto 380:  ¡Me caso!
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
    int gasnum;
    int gas;
    long toalgas;
    while(cin>>gasnum&&gasnum){
        toalgas=0;
        for(int i=0;i<gasnum;++i){
            cin>>gas;
            toalgas+=gas;
        }
        cout<<toalgas<<"\n";
    }
    return 0;
}

