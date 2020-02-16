// AceptaElReto 159:  Viendo pasar el tiempo
//
//  main.cpp
//  159
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <algorithm>
bool hour[24][10];
bool minut[60][10];
using namespace std;
void preprocess(){
    string s;
    for(int i=0;i<10;i++){
        //minutes
        for(int j=0;j<24;j++){
            hour[j][i]= (j/10==i)||(j%10==i);
            minut[j][i]= (j/10==i)||(j%10==i);
        }
        for(int j=24;j<60;j++){
            minut[j][i]= (j/10==i)||(j%10==i);
        }
        
    }
}
int main(int argc, const char * argv[]) {
    int h1,m1,h2,m2,digit;
    int sum;
    preprocess();
    while(scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&digit)&&(h1!=24)) {
        sum=0;
        if(h1<h2){
            if(hour[h1][digit]){
                sum+=60-m1;
            }
            else{
                for(int j=m1;j<60;j++){
                    sum+=minut[j][digit];
                }
            }
            
            for(int i=h1+1;i<h2;i++){
                if(hour[i][digit]){
                    sum+=60;
                    continue;
                }
                for(int j=0;j<60;j++){
                    sum+=minut[j][digit];
                }
            }
            if(hour[h2][digit]){
                sum+=m2+1;
            }
            else{
                for(int j=0;j<=m2;j++){
                    sum+=minut[j][digit];
                }
            }
            
        }
        else{
            //Same hour
            for(int j=m1;j<=m2;j++){
                sum+=hour[h1][digit]||minut[j][digit];
            }
        }
        
        printf("%d\n",sum);
        
    }
    return 0;
}
