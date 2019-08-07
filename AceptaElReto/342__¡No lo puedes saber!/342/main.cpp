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
#define mp(x,y) make_pair(x,y)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int r_limit,l_limit,target;
    int l_dist,r_dist,guess,ng;
    while(cin>>r_limit>>l_limit>>target and r_limit){
        cin>>ng;
        l_dist=l_limit-target+1;
        r_dist=target-r_limit+1;
        for(int i=0;i<ng;++i){
            cin>>guess;
                if(guess<=target){
                    r_dist=min(r_dist,target-guess+1);
                }
                else{
                    l_dist=min(l_dist,guess-target);
                }
        }
        if(l_dist<=1 and r_dist<=1){
            cout<<"LO SABE\n";
        }
        else cout<<"NO LO SABE\n";
    }
    return 0;
}

