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
    cin>>cas;
    int up,down;
    long long range;
    long long floor;
    for(int i=0;i<cas;++i){
        cin>>up>>down;
        floor=up+down;
        if(floor==0){
            cout<<"1\n";
            continue;
        }
        range=(floor*(floor+1))/2;
        range+=(floor-down);
        range++;
        cout<<range<<"\n";
    }
    return 0;
}

