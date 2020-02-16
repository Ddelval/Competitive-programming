// AceptaElReto 459:  Presupuestando semáforos
//
//  main.cpp
//  459
//
//  Created by David del Val on 17/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int board [1000][1000];
int width;
int depth;
void coutboard(){
    int i,j;
    for(i=0;i<depth;++i){
        for(j=0;j<width;++j){
            printf("%3d ",board[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    char c;
    int i,j;
    int ady;
    int semafor;
    int pw=0,pd=0;
    while(cin>>width>>depth&&width&&depth){
        if(pw&&pd){
            for(i=0;i<pd;++i){
                for(j=0;j<pw;++j){
                    if(board[i][j]){
                       board[i][j]=0;
                    }
                    
                }
            }
        }
        for(i=0;i<depth;++i){
            for(j=0;j<width;++j){
                cin>>c;
                if(c=='#'){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }
        }
        //coutboard();
        semafor=0;
        for(i=0;i<depth;++i){
            for(j=0;j<width;++j){
                ady=0;
                if(i!=0&&board[i-1][j]){
                    ady++;
                }
                if(j!=0&&board[i][j-1]){
                    ady++;
                }
                if(i!=depth-1&&board[i+1][j]){
                    ady++;
                }
                if(j!=width-1&&board[i][j+1]){
                    ady++;
                }
                if(ady>2&&board[i][j]){
                    semafor+=ady;
                }
            }
        }
        cout<<semafor<<"\n";
        pw=width;
        pd=depth;
        
        
    }
    
    return 0;
}
