//
//  main.cpp
//  113
//
//  Created by David del Val on 06/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
typedef struct{
    double dista;
    int closed;
    int open;
    int cycle;
    
}semaf;

semaf data[101];
int numsem;
double velmax;
double remind(double a, int b){
    double c=a-(((int)(a/b)))*b;
    return c;

}
bool check(double speed,double stime, int index){
    double endtime= stime + data[index].dista/speed;
    if(index==numsem-1){
        return true;
    }
    if((remind(endtime,data[index].cycle)>=data[index].closed)||!(remind(endtime,data[index].cycle))){
        return check(speed, endtime, index+1);
    }
    return false;
}

using namespace std;
int main(int argc, const char * argv[]) {
    int t1,t2;
    scanf("%d",&numsem);
    scanf("%d",&t1);
    velmax=t1;
    bool flag;
    double totalength;
    double speed;
    int clockindex=0;
    while(numsem||velmax){
        totalength=0;
        clockindex=0;
        flag=false;
        semaf s;
        for(int i=0;i<numsem;i++){
            scanf("%d",&t1);
            s.dista=t1;
            totalength+=s.dista;
            scanf("%d",&s.closed);
            scanf("%d",&s.open);
            if(!s.open){
                flag=true;
            }
            s.cycle=s.closed+s.open;
            data[i]=s;
        }
        if(flag){
            printf("IMPOSIBLE\n");
            scanf("%d",&numsem);
            scanf("%d",&t2);
            velmax=t2;
            continue;
        }
        speed=totalength/s.closed;
        while(1){
            
            if(speed<=velmax){
                break;
            }
            clockindex++;
            speed=totalength/s.cycle*(clockindex);
            
            if(speed<=velmax){
                break;
            }
            speed=totalength/(s.closed+(clockindex-1)*s.cycle);
        }
        while(speed>=0.1){
            if(speed&&check(speed, 0, 0)){
                break;
            }
            if(clockindex){
                speed=totalength/(s.cycle*(clockindex));
            }
            if(speed&&check(speed, 0, 0)){
                break;
            }
            speed=totalength/(s.closed+(clockindex)*s.cycle);
            clockindex++;
        }
        if(speed<0.1){
            printf("IMPOSIBLE\n");
        }
        else{
            printf("%d\n",(int)totalength/(int)speed);
        }
        
        
        
        
        scanf("%d",&numsem);
        scanf("%d",&t2);
        velmax=t2;

    }
    
    return 0;
}
