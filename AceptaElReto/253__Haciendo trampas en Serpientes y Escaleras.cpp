// AceptaElReto 253:  Haciendo trampas en Serpientes y Escaleras
//
//  main.cpp
//  253
//
//  Created by David del Val on 18/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int n,k,s,e;
int totn;
int x,y;
typedef pair<int ,int> snake;
typedef pair<int,int> ladder;
void get(int num){
    y=num/n;
    if(!(y%2)){
        x=num%n;
    }
    else{
        x=n-num%n;
    }
}
int main(int argc, const char * argv[]) {
    int arg0,arg1;
    vector <int> points;
    int board [100][100];
    int indic [100]={0};
    scanf("%d %d %d %d",&totn,&k,&s,&e);
    n=sqrt(totn);
    for(int i=0;i<totn;i++){
        indic[i]=0;
        for(int j=0;j<totn;j++){
            board[i][j]=-100;
            
        }
    }
    indic[0]='T';
    indic[n-1]='F';
    for(int i=0;i<s;i++){
        cin>>arg0>>arg1;
        arg0--;
        arg1--;
        indic[arg0]='S';
        
        snake s;
        s.first=arg0;
        s.second=arg1;
    }
    for(int i=0;i<e;i++){
        cin>>arg0>>arg1;
        arg0--;
        arg1--;
        indic[arg0]='E';
        
        ladder l;
        l.first=arg0;
        l.second=arg1;
    }
    
    return 0;
}
