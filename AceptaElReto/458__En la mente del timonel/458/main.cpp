// AceptaElReto 458:  En la mente del timonel
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <limits.h>
#include <queue>
using namespace std;
int data[200000];
int main() {
    ios::sync_with_stdio(false);
    priority_queue<long> pq;
    int length;
    long long min1,min2,max1,max2,i;
    bool b,g;
    while(cin>>length&&length){
        min1=min2=INT_MAX;
        max1=max2=-INT_MAX;
        for(i=0;i<length;++i){
            cin>>data[i];
        }
        for(i=0;i<length;++i){
            if(data[i]>max1){
                max1=data[i];
            }
            if(data[i]<min1){
                min1=data[i];
            }
        }
        b=g=false;
        for(i=0;i<length;++i){
            if(b||data[i]!=max1){
                if(data[i]>max2) max2=data[i];
            }
            if(data[i]==max1){
                b=true;
            }
            
            if(g||data[i]!=min1){
                if(data[i]<min2) min2=data[i];
            }
            if(data[i]==min1){
                g=true;
            }
        }
        if(min2==INT_MAX){
            cout<<min1*max1<<"\n";
        }
        else if(min2*min1>max2*max1){
            cout<<min2*min1<<"\n";
        }
        else{
            cout<<max2*max1<<"\n";
        }
    }
    return 0;
}

