// AceptaElReto 328:  La comida de los pollitos
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int width,height, chickens;
int board[50][50];
void coutboard(){
    for(int i=0;i<height;++i){
        for(int j=0;j<width-1;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<board[i][width-1]<<"\n";
    }
}

/**
 0: move right
 1: move down
 2: move left
 3: move up
 */
void movechicken(int limit,int dir,int sx,int sy){
    board[sx][sy]++;
    int changedir=0;
    int currentmove=0;
    int currentmovelimit=1;
    bool moving=true;
    
    for(int tick=0;tick<limit&&moving;tick++){
        switch(dir){
            case 0:{
                if(sy+1==width){moving=false;break;}
                sy++;
                board[sx][sy]++;
                break;
            }
            case 1:{
                if(sx+1==height){moving=false;break;}
                sx++;
                board[sx][sy]++;
                break;
            }
            case 2:{
                if(sy-1==-1){moving=false;break;}
                sy--;
                board[sx][sy]++;
                break;
            }
            case 3:{
                if(sx-1==-1){moving=false;break;}
                sx--;
                board[sx][sy]++;
                break;
            }
                
        }
        currentmove++;
        if(currentmove==currentmovelimit){
            dir+=1;
            dir%=4;
            changedir++;
            currentmove=0;
        }
        if(changedir==2){
            changedir=0;
            currentmovelimit++;
        }
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    int x,y,awake,d;
    char dir;
    int cas;
    cin>>cas;
    for(int z=0;z<cas;++z){
        cin>>height>>width>>chickens;
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                board[i][j]=0;
            }
        }
        for(int i=0;i<chickens;++i){
            cin>>x>>y>>dir>>awake;
            x--;
            y--;
            switch(dir){
                case 'E': d=0; break;
                case 'S': d=1; break;
                case 'W': d=2; break;
                case 'N': d=3; break;
            }
            movechicken(awake,d,x,y);
           
        }
        coutboard();
        cout<<"---\n";
        
    }
    return 0;
}

