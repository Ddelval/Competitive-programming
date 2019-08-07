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
int lturn,rturn;
int width,height;
int board[100][100];
int deplace[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dir;
//0 going right
//1 going down
//2 going left
//3 going up
void explore(int x,int y){
    int x1,y1;
    if(x+1<height&&board[x+1][y]){
        dir=1;
        x1=x+1;
        y1=y;
    }
    else{
        dir=0;
        y1=y+1;
        x1=x;
    }
    do{
        x1=x+deplace[dir][0];
        y1=y+deplace[dir][1];
        if(x1>=0&&y1>=0&&x1<height&&y1<width&&board[x1][y1]){
            x=x1;
            y=y1;
            continue;
        }
        else{
            switch(dir){
                case 0:{
                    x1=x+deplace[1][0];
                    y1=y+deplace[1][1];
                    if(x1>=0&&y1>=0&&x1<height&&y1<width&&board[x1][y1]){
                        x=x1;
                        y=y1;
                        dir=1;
                        rturn++;
                        continue;
                    }
                    x1=x+deplace[3][0];
                    y1=y+deplace[3][1];
                    lturn++;
                    dir=3;
                    x=x1;
                    y=y1;
                    break;
                }
                case 2:{
                    x1=x+deplace[1][0];
                    y1=y+deplace[1][1];
                    dir=1;
                    if(x1>=0&&y1>=0&&x1<height&&y1<width&&board[x1][y1]){
                        x=x1;
                        y=y1;
                        lturn++;
                        continue;
                    }
                    x1=x+deplace[3][0];
                    y1=y+deplace[3][1];
                    x=x1;
                    dir=3;
                    rturn++;
                    y=y1;
                    break;
                }
                case 1:{
                    x1=x+deplace[0][0];
                    y1=y+deplace[0][1];
                    dir=0;
                    if(x1>=0&&y1>=0&&x1<height&&y1<width&&board[x1][y1]){
                        x=x1;
                        y=y1;
                        lturn++;
                        continue;
                    }
                    x1=x+deplace[2][0];
                    y1=y+deplace[2][1];
                    dir=2;
                    rturn++;
                    x=x1;
                    y=y1;
                    break;
                }
                case 3:{
                    x1=x+deplace[0][0];
                    y1=y+deplace[0][1];
                    dir=0;
                    if(x1>=0&&y1>=0&&x1<height&&y1<width&&board[x1][y1]){
                        x=x1;
                        y=y1;
                        rturn++;
                        continue;
                    }
                    x1=x+deplace[2][0];
                    y1=y+deplace[2][1];
                    dir=2;
                    lturn++;
                    x=x1;
                    y=y1;
                    break;
                }
            }
        }
    }while(board[x][y]!=5);
    
    
}
int main() {
    ios::sync_with_stdio(false);
    char c;
    int x,y;
    while(cin>>width>>height){
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                cin>>c;
                if(c=='.'){
                    board[i][j]=0;
                }
                else if(c=='O'){
                    x=i;
                    y=j;
                    board[i][j]=5;
                }
                else{
                    board[i][j]=1;
                }
            }
        }
        lturn=0;
        rturn=0;
        explore(x,y);
        if(lturn>rturn){
            swap(lturn,rturn);
        }
        cout<<lturn<<" "<<rturn<<"\n";
    }
    
    return 0;
}

