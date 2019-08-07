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
int roadcounter;
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
void exploreroad(int x, int y){
     //coutboard();
    if(x!=0&&!board[x-1][y]){
        board[x][y]=roadcounter;
        exploreroad(x-1,y);
    }
    else if(y!=0&&!board[x][y-1]){
        board[x][y]=roadcounter;
        exploreroad(x,y-1);
    }
    else if(y!=depth-1&&!board[x][y+1]){
        board[x][y]=roadcounter;
        exploreroad(x,y+1);
    }
    else if(x!=width-1&&!board[x+1][y]){
        board[x][y]=roadcounter;
        exploreroad(x+1,y);
    }
   
        board[x][y]=roadcounter;
    
    
    
}
int main(int argc, const char * argv[]) {
    char c;
    int i,j;
    int prev,curr;
    int intersec;
    while(cin>>width>>depth){
        roadcounter=0;
        for(i=0;i<depth;++i){
            for(j=0;j<width;++j){
                cin>>c;
                if(c=='#'){
                    board[i][j]=0;
                }
                else{
                    board[i][j]=-1;
                }
            }
        }
        coutboard();
        
        i=0;
        j=depth-1;
        while(i<=j){
            for(int x=0;x<width;x++){
                if(!board[i][x]){
                    roadcounter++;
                    exploreroad(i,x);
                    coutboard();
                }
            }
            if(i==j){
                break;
            }
            for(int x=width-1;x>=0;x--){
                if(!board[j][x]){
                    roadcounter++;
                    exploreroad(j,x);
                    coutboard();
                }
            }
            i++;
            j--;
        }
        intersec=0;
        coutboard();
        for(i=0;i<depth;++i){
            prev=board[i][0];
            for(j=1;j<width;++j){
                curr=board[i][j];
                if(curr!=prev&&curr!=-1&&prev!=-1){
                    intersec+=2;
                    if(i>0&&board[i-1][j]!=-1){
                        intersec++;
                    }
                    if(j>0&&board[i][j-1]!=-1){
                        intersec++;
                    }
                    board[i][j]=-1;
                    coutboard();
                }
                prev=curr;
            }
        }
        coutboard();
        for(i=0;i<depth;++i){
            prev=board[j][i];
            for(j=1;j<width;++j){
                curr=board[j][0];
                if(curr!=prev&&curr!=-1&&prev!=-1){
                    intersec+=2;
                    if(i>0&&board[j-1][i]!=-1){
                        intersec++;
                    }
                    if(j>0&&board[j][i-1]!=-1){
                        intersec++;
                    }
                    board[j][i]=-1;
                    coutboard();
                }
                prev=curr;
            }
        }
        cout<<intersec<<"\n";
        
        
        
    }
    
    return 0;
}
