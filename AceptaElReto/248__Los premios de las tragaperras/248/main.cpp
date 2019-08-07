// AceptaElReto 248:  Los premios de las tragaperras
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
long long maxim(long long a, long long b){
    if(a>b){
        return a;
    }
    return b;
}
int main() {
    ios::sync_with_stdio(false);
    int length,i;
    long long max;
    int priz;
    long long currentmoney;
    long long initialpos,initialmoney;
    long long totalsum;
    long long maxtotalsum;
    bool b,firstsave,firstpos;
    while(cin>>length&&length){
        max=0;
        currentmoney=0;
        totalsum=0;
        maxtotalsum=0;
        for(i=0;i<length;++i){
            cin>>priz;
            currentmoney+=priz;
            totalsum+=priz;
            if(currentmoney<0){
                currentmoney=0;
            }
            else{
                if(currentmoney>max){
                    max=currentmoney;
                }
            }
            if(totalsum>maxtotalsum){
                maxtotalsum=totalsum;
            }
        }
        if(currentmoney>0){
            max=maxim(max,currentmoney+maxtotalsum);
        }
        cout<<max<<"\n";
    }
    return 0;
}

