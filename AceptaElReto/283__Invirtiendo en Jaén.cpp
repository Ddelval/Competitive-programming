// AceptaElReto 283:  Invirtiendo en Jaén
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
bool board[100][100];
int height,width;
int size;
void print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ",(int)board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void DFS(int x,int y){
    board[x][y]=false;
    if(x>0&&board[x-1][y]){
        DFS(x-1,y);
    }
    if(y>0&&board[x][y-1]){
        DFS(x,y-1);
    }
    if(y!=width-1&&board[x][y+1]){
        DFS(x,y+1);
    }
    if(x!=height-1&&board[x+1][y]){
        DFS(x+1,y);
    }
    size++;
    
}
int main() {
    ios::sync_with_stdio(false);
    int maxsize;
    int i,j;
    string s;
    while(getline(cin,s)){
        maxsize=0;
        height=stoi(s.substr(0,s.find(' ')));
        width=stoi(s.substr(s.find(' ')));
        for(i=0;i<height;++i){
            getline(cin,s);
            for(j=0;j<width;++j){
                if(s[j]=='#'){
                    board[i][j]=true;
                }
                else{
                    board[i][j]=false;
                }
            }
        }
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                if(board[i][j]){
                    size=0;
                    DFS(i,j);
                    if(size>maxsize){
                        maxsize=size;
                    }
                }
            }
        }
        cout<<maxsize<<"\n";
        
        
    }
    return 0;
}

