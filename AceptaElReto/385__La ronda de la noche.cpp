// AceptaElReto 385:  La ronda de la noche
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
char board[1000][1000];
bool visited[1000][1000];
int sx,sy,ex,ey;
int width,height;
void out(){
    cout<<endl;
    for(int i=0;i<height;++i){
        for(int j=0;j<width;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int BFS(){
    queue<pair<pair<short,short>,int>> toprocess;
    int x,y,l;
    toprocess.push(make_pair(make_pair(sx,sy),0));
    visited[sx][sy]=true;
    while(!toprocess.empty()){
        x=toprocess.front().first.first;
        y=toprocess.front().first.second;
        l=toprocess.front().second;
        toprocess.pop();
        if(x==ex&&y==ey){
            return l;
        }
        if(x!=height-1&&(board[x+1][y]=='.'||board[x+1][y]=='P')&&!visited[x+1][y]){
            toprocess.push(make_pair(make_pair(x+1,y),l+1));
            visited[x+1][y]=true;
        }
        if(y!=width-1&&(board[x][y+1]=='.'||board[x][y+1]=='P')&&!visited[x][y+1]){
            toprocess.push(make_pair(make_pair(x,y+1),l+1));
            visited[x][y+1]=true;
        }
        if(x&&(board[x-1][y]=='.'||board[x-1][y]=='P')&&!visited[x-1][y]){
            toprocess.push(make_pair(make_pair(x-1,y),l+1));
            visited[x-1][y]=true;
        }
        if(y&&(board[x][y-1]=='.'||board[x][y-1]=='P')&&!visited[x][y-1]){
            toprocess.push(make_pair(make_pair(x,y-1),l+1));
            visited[x][y-1]=true;
        }
    }
    
    
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    int cas,m,lim,res;
    string s;
    cin>>cas;
    for(int i=0;i<cas;++i){
        //Input
        cin>>width>>height;
        if(!width||!height){
            cout<<"NO\n";
            continue;
        }
        getline(cin,s);
        sx=-1;
        sy=-1;
        ex=-1;
        ey=-1;
        for(int j=0;j<height;j++){
            getline(cin,s);
            for(int w=0;w<width;++w){
                board[j][w]=s[w];
                visited[j][w]=false;
                if(board[j][w]=='E'){
                    sx=j;
                    sy=w;
                }
                else if(board[j][w]=='P'){
                    ex=j;
                    ey=w;
                }
            }
        }
        if(sx==-1||sy==-1||ex==-1||ey==-1){
            cout<<"NO\n";
            continue;
        }
        //Deal with the detectors
        
        for(int j=0;j<height;j++){
            for(int w=0;w<width;++w){
                if(board[j][w]>='0'&&board[j][w]<='9'){
                    lim=board[j][w]-'0';
                    for(m=1;m<=lim&&(w+m)<width;m++){
                        if(board[j][w+m]=='#'){
                            break;
                        }
                        if(board[j][w+m]=='.'||board[j][w+m]=='E'||board[j][w+m]=='P'){
                            board[j][w+m]='R';
                        }
                        
                    }
                    for(m=1;m<=lim&&(j+m)<height;m++){
                        if(board[j+m][w]=='#'){
                            break;
                        }
                        if(board[j+m][w]=='.'||board[j+m][w]=='E'||board[j+m][w]=='P'){
                            board[j+m][w]='R';
                        }
                        
                    }
                    for(m=1;m<=lim&&(w-m)>=0;m++){
                        if(board[j][w-m]=='#'){
                            break;
                        }
                        if(board[j][w-m]=='.'||board[j][w-m]=='E'||board[j][w-m]=='P'){
                            board[j][w-m]='R';
                        }
                    }
                    for(m=1;m<=lim&&(j-m)>=0;m++){
                        if(board[j-m][w]=='#'){
                            break;
                        }
                        if(board[j-m][w]=='.'||board[j-m][w]=='E'||board[j-m][w]=='P'){
                            board[j-m][w]='R';
                        }
                        
                    }
                    board[j][w]='R';
                }
            }
        }
        //out();
        //If there was a detector affecting the starting or ending position...
        if(board[sx][sy]!='E'||board[ex][ey]!='P'){
            cout<<"NO\n";
            continue;
        }
        res=BFS();
        if(res==-1){
            cout<<"NO\n";
        }
        else{
            cout<<res<<"\n";
        }
    }
    return 0;
}

