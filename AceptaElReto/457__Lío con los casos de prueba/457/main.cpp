#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;
int num[250000];
int possiblenum;
void explore(int accumnum,int cursor){
    cursor--;
    if(cursor<0){
        if(accumnum){
            if(accumnum<possiblenum){
                possiblenum=accumnum;
            }
        }
        return;
    }
    if(num[cursor]==accumnum){
        explore(0,cursor);
    }
    explore(accumnum+1,cursor);
    
}
int main() {
    ios::sync_with_stdio(false);
    int length;
    while(cin>>length&&length){
        for(int i=0;i<length;++i){
            cin>>num[i];
        }
        if(length==1){
            cout<<"1\n";
            continue;
        }
        possiblenum=INT_MAX;
        explore(1,length-1);
        cout<<possiblenum<<"\n";
    }
    return 0;
}

