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
struct Inter{
    int begin=1,end=1;
    long long weight=0;
};
Inter maxim;
/**
 @return 0 if lengths are equal
         1 if a is longer than b
         2 otherwise
 */
int shorter(Inter a, Inter b){
    int dur1,dur2;
    dur1=a.end-a.begin;
    dur2=b.end-b.begin;
    if(dur1==dur2){
        return 0;
    }
    else if(dur1>dur2){
        return 1;
    }
    else{
        return 2;
    }
}
Inter newmax(Inter max, Inter candidate){
    if(max.weight<candidate.weight){
        return candidate;
    }
    switch(shorter(max,candidate)){
        case 0:{
            if(candidate.begin<max.begin){
                return candidate;
            }
            return max;
            break;
        }
        case 1: return candidate;
    }
    return max;
}
void updateMax(int begin,int end,long long weight){
    Inter propose;
    propose.weight=weight;
    propose.begin=begin;
    propose.end=end;
    maxim=newmax(maxim,propose);
}
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int length;
    int s,e;
    long long partialsum;
    int val;
    cin>>cas;
    for(int i=0;i<cas;++i){
        partialsum=0;
        maxim=Inter();
        s=1;
        e=1;
        cin>>length;
        for(int j=1;j<=length;++j){
            cin>>val;
            partialsum+=val;
            if(partialsum<=0){
                partialsum=0;
                s=j+1;
            }
            else{
                if(partialsum>=maxim.weight){
                    updateMax(s,j,partialsum);
                }
            }
        }
        if(s<=length){
            if(partialsum>=maxim.weight){
                updateMax(s,length,partialsum);
            }
        }
        
        cout<<maxim.begin<<" "<<maxim.end<<"\n";
    }
    return 0;
}

