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
int board[20][20];
int width,height;
int sx,sy,ex,ey;
int y[4]={0,1,0,-1};
int x[4]={1,0,-1,0};
bool visited[20][20];
bool BFS(){
    queue<pair<int,int>> qp;
    int cx,cy,a,b,i;
    qp.push(make_pair(sx,sy));
    visited[sx][sy]=true;
    while(!qp.empty()){
        cx=qp.front().first;
        cy=qp.front().second;
        if(cx==ex&&cy==ey){
            return true;
        }
        qp.pop();
        for(i=0;i<4;++i){
            a=cx+x[i];
            b=cy+y[i];
            if(a>=0&&b>=0&&a<height&&b<width&&board[a][b]&&!visited[a][b]){
                qp.push(make_pair(a,b));
                visited[a][b]=true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    int i,j;
    char c;
    while(cin>>height>>width){
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                cin>>c;
                visited[i][j]=false;
                if(c=='*'){
                    board[i][j]=0;
                    continue;
                }
                if(c=='F'){
                    ex=i;
                    ey=j;
                }
                else if(c=='S'){
                    sx=i;
                    sy=j;
                }
                board[i][j]=1;
            }
        }
        if(BFS())cout<<"SI\n";
        else     cout<<"NO\n";
    }
    return 0;
}

