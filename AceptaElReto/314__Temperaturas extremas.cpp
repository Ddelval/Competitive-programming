// AceptaElReto 314:  Temperaturas extremas
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
    int length;
    int cas;
    int left,right,current;
    int up,down;
    cin>>cas;
    for(int j=0;j<cas;++j){
        cin>>length;
        if(length<3){
            for(int i=0;i<length;++i){
                cin>>left;
            }
            cout<<"0 0\n";
            continue;
        }
        cin>>left;
        cin>>current;
        up=down=0;
        for(int i=2;i<length;++i){
            cin>>right;
            if(left<current&&right<current){
                up++;
            }
            else if(left>current&&right>current){
                down++;
            }
            left=current;
            current=right;
        }
        cout<<up<<" "<<down<<"\n";
    }
    return 0;
}

