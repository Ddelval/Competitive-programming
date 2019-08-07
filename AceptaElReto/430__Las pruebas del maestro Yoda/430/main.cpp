// AceptaElReto 430:  Las pruebas del maestro Yoda
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
    int start,wait,i,x,y;
    int current_time;
    while(cin>>length&&length){
        if(length==1){
            cin>>start>>wait;
            cout<<start<<"\n";
            continue;
        }
        cin>>current_time>>wait;
        for(i=1;i<length;++i){
            cin>>start>>wait;
            if(start>current_time){
                current_time=start;
            }
            else{
                x=start-current_time;
                
                    //Now we have to find the first number that satisfies k=x+wait*y
                    y=ceil(-x/(double)wait);
                
                if(start+y*wait==current_time){
                    y++;
                }
                current_time=start+y*wait;
            }
        }
        cout<<current_time<<"\n";
        
        
    }
    return 0;
}

