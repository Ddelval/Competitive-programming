//
//  main.c
//  0993
//
//  Created by David del Val on 20/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

long  number;
long division;
int j,i;
int exists=1;
int cases;
int sixcount=0;
int ninecounter=0;
int eightcount=0;
int fourcounter=0;
int main() {
    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        exists=1;
        sixcount=0;
        eightcount=0;
        fourcounter=0;
        ninecounter=0;
        scanf("%ld",&number);
        division=number;
        if(number>1){
            while(division>=2&&exists){
                if(!(division%2)){
                    division=division/2;
                }
                else if(!(division%3)){
                    division=division/3;
                }
                else if(!(division%5)){
                    division=division/5;
                }
                else if(!(division%7)){
                    division=division/7;
                }
                else{
                    exists =0;
                }
            }
        }
        
        if(exists){
            division=number;
            if(division==1){
                printf("1");
            }
            else{
                while(division>=2){
                    if(!(division%9)){
                        ninecounter++;
                        division=division/9;
                    }
                    else{
                        if(!(division%8)){
                            eightcount++;
                            division=division/8;
                        }
                        else{
                            if(!(division%6)){
                                sixcount++;
                                division=division/6;
                            }
                            else{
                                if(!(division%4)){
                                    fourcounter++;
                                    division=division/4;
                                }
                                else{
                                    if(!(division%2)){
                                        printf("2");
                                        division=division/2;
                                    }
                                    else if(!(division%3)){
                                        printf("3");
                                        division=division/3;
                                    }
                                }
                                
                            }
                        }
                    }
                    
                    
                    if(!(division%5)){
                        while(fourcounter>0){
                            printf("4");
                            fourcounter--;
                        }
                        printf("5");
                        division=division/5;
                    }
                    else if(!(division%7)){
                        
                        while(sixcount>0){
                            printf("6");
                            sixcount--;
                        }
                        
                        printf("7");
                        division=division/7;
                    }
                    
                    
                }
                while(fourcounter>0){
                    printf("4");
                    fourcounter--;
                }
                if(sixcount>0){
                    while(sixcount>0){
                        printf("6");
                        sixcount--;
                    }
                }
                if(eightcount>0){
                    while(eightcount>0){
                        printf("8");
                        eightcount--;
                    }
                }
                if(ninecounter>0){
                    while(ninecounter>0){
                        printf("9");
                        ninecounter--;
                    }
                }
            }
            
            
            printf("\n");
        }
        else{
            printf("-1\n");
        }
    }
    
    return (0);
}

