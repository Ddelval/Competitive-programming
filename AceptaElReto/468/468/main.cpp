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
    int absmax,length,max,min,n;
    while(cin>>length){
        cin>>max;
        min=max;
        absmax=0;
        for(int i=1;i<length;++i){
            cin>>n;
            if(n<min){
                min=n;
                max=n;
            }
            else if(n>max){
                max=n;
                if(max-min>absmax){
                    absmax=max-min;
                }
            }
            
        }
        cout<<absmax<<"\n";
    }
    return 0;
}

