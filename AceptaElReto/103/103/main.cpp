//
//  main.cpp
//  103
//
//  Created by David del Val on 21/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int grado;
    double polinom[19];
    double aprox;
    double localvalue;
    double totalvalue;
    cin>>grado;
    while(grado!=20){
        for(int i=0;i<=grado;i++){
            cin>>polinom[grado-i];
        }
        cin>>aprox;
        totalvalue=0;
        for(int i=0;i<aprox;i++){
            localvalue=0;
            for(int j=1;j<=grado;j++){
                localvalue+=(polinom[j]*pow(i/aprox, j));
            }
            localvalue+=polinom[0];
            if(localvalue<0){
                localvalue=0;
            }
            else if(localvalue>1){
                localvalue=1;
            }
            totalvalue+=(localvalue/aprox);
        }
        if((totalvalue-0.5)<0.001&&(totalvalue-0.5)>-0.001){
            cout<<"JUSTO\n";
        }
        else if(totalvalue>0.5){
            cout<<"CAIN\n";
        }
        else{
            cout<<"ABEL\n";
        }
        for(int i=0;i<=grado;i++){
            polinom[grado-i]=0;
        }
        cin>>grado;
    }
    
    return 0;
}
