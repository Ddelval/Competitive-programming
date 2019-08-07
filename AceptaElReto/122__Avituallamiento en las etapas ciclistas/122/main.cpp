// AceptaElReto 122:  Avituallamiento en las etapas ciclistas
//
//  main.cpp
//  122
//
//  Created by David del Val on 02/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int argument;
    int maximumflat=0;
    int startflat=0;
    int previosv=-1;
    int currentflat=0;
    int currentstart=0;
    int index=0;
    
    while (1){
        scanf("%d",&argument);
        if(argument==-1&&!index){
            break;
        }
        while(argument>=0){
            if(previosv==argument){
                if(!currentflat){
                    currentstart=index-1;
                }
                currentflat++;
            }
            else{
                if(currentflat){
                    if(currentflat>maximumflat){
                        maximumflat=currentflat;
                        startflat=currentstart;
                    }
                    currentflat=0;
                }
            }
            index++;
            previosv=argument;
            scanf("%d",&argument);
        }
        if(currentflat>maximumflat){
            printf("%d %d\n",currentstart,currentflat);
        }
        else{
            if(!maximumflat){
                printf("HOY NO COMEN\n");
            }
            else{
                printf("%d %d\n",startflat,maximumflat);
            }
            
        }
        maximumflat=0;
        startflat=0;
        previosv=-1;
        currentflat=0;
        currentstart=0;
        index=0;
    }
    return 0;
}
