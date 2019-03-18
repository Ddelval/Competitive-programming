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
    vector<int> balls;
    int ball,accuracy,size;
    int counter,out;
    while(cin>>ball>>accuracy&&(ball||accuracy)){
        balls.clear();
        for(int i=1;i<=ball;i++){
            balls.push_back(i);
        }
        counter=0;
        size=ball;
        for(auto it=balls.begin();size>1;it++){
            if(it==balls.end()){
                it=balls.begin();
            }
            if(*it==1000){
                continue;
            }
            counter++;
            if(counter==accuracy){
                *it=1000;
                size--;
                counter=0;
            }
        }
        for(auto it=balls.begin();it!=balls.end();it++){
            if(*it!=1000){
                out=*it;
                break;
            }
            
        }
        cout<<out<<"\n";
    }
    return 0;
}

