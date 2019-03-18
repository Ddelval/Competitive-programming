//
//  main.cpp
//  131
//
//  Created by David del Val on 02/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
#include <limits>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    long mypool;
    long mybucket,mylose;
    long hispool;
    long hisbucket, hislose;
    long mytravels,histravels;
    scanf("%ld %ld %ld %ld %ld %ld",&mypool,&mybucket,&mylose,&hispool,&hisbucket,&hislose);
    while(mypool&&hispool){
        if(mybucket>=mypool){
            mytravels=1;
        }
        else if((mybucket-mylose)<=0){
            mytravels= 0;
        }
        else{
            mytravels=((mypool-mybucket)%(mybucket-mylose)>0)+((mypool-mybucket)/(mybucket-mylose))+1;
        }
        if(hisbucket>=hispool){
            histravels=1;
        }
        else if ((hisbucket-hislose)<=0){
            histravels= 0;
        }
        else{
            histravels=(((hispool-hisbucket)%(hisbucket-hislose)>0)+((hispool-hisbucket)/(hisbucket-hislose)))+1;
        }
        if(histravels==mytravels){
            printf("EMPATE %ld\n",histravels);
        }
        else if(((mytravels>histravels )&&histravels)||!mytravels){
            printf("VECINO %ld\n",histravels);
        }
        else{
            printf("YO %ld\n",mytravels);
        }
        scanf("%ld %ld %ld %ld %ld %ld",&mypool,&mybucket,&mylose,&hispool,&hisbucket,&hislose);
    }
    
    
    return 0;
}
