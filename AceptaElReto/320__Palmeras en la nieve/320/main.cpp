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
queue<int> ipos;
int main() {
    ios::sync_with_stdio(false);
    int cas,snow,length,pal,count,max,diff;
    cin>>cas;
    for(int i=0;i<cas;++i){
        cin>>snow>>length;
        max=1;
        count=diff=0;
        ipos=queue<int>();
        ipos.push(-1);
        for(int j=0;j<length;++j){
            cin>>pal;
            if(pal>=snow){
                count++;
                ipos.push(j);
            }
            else continue;
            if(count>5){
                diff=j-ipos.front()-1;
                if(diff>max) max=diff;
                ipos.pop();
                count--;
            }
        }
        if(count<=5){
            diff=length-ipos.front()-1;
            if(diff>max) max=diff;
            ipos.pop();
            count--;
        }
        cout<<max<<"\n";
    }
    return 0;
}

