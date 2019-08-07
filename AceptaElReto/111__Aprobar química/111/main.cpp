// AceptaElReto 111:  Aprobar química
//
//  main.cpp
//  111
//
//  Created by David del Val on 09/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
const int  maxvalues[]={2  ,2   ,6   ,2   ,6   ,2   ,10  ,6   ,2   ,10  ,6   , 2  ,14  ,10  ,6   ,2   ,14  ,10  ,6};
const int  parsum[]   ={2  ,4   ,10  ,12  ,18  ,20  ,30  ,36  ,38  ,48  ,54  ,56  ,70  ,80  ,86  ,88  ,102 ,112 ,118};
const char let[19][3]={"1s","2s","2p","3s","3p","4s","3d","4p","5s","4d","5p","6s","4f","5d","6p","7s","5f","6d","7p"};
const char lets[19][5]={"1s2","2s2","2p6","3s2","3p6","4s2","3d10","4p6","5s2","4d10","5p6","6s2","4f14","5d10","6p6","7s2","5f14","6d10","7p6"};
int main(int argc, const char * argv[]) {
    string name;
    int z=37;
    int i;
    int dif;
    i=0;
    cin>>name;
    while(name!="Exit"){
        scanf("%d",&z);
        if(!z){
            cout<<"1s0"<<endl;
            cin>>name;
            continue;
        }
        i=0;
        for(i=0;z>parsum[i];i++){
            printf("%s ",lets[i]);
        }
        if(z==parsum[i]){
            printf("%s",lets[i]);
        }
        else{
            dif=parsum[i]-z;
            dif=maxvalues[i]-dif;
            printf("%s%d",let[i],dif);
        }
        cout<<endl;
        cin>>name;
    }
    
    return 0;
}
