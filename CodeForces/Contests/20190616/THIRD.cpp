//
//  main.cpp
//  THIRD
//
//  Created by David del Val on 16/06/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <string.h>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";
#define LIM 1005
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
char board[LIM][LIM];
int n,m;
bool validFlag(int x,int y, int h){
    char c1,c2,c3;
    c1=board[x][y];
    for(int i=1;i<h;++i){
        if(board[x+i][y]!=c1) return false;
    }
    c2=board[x+h][y];
    if(c1==c2)return false;
    for(int i=1;i<h;++i){
        if(board[x+i+h][y]!=c2) return false;
    }
    c3=board[x+h+h][y];
    if(c3==c2)return false;
    for(int i=1;i<h;++i){
        if(board[x+i+h+h][y]!=c3) return false;
    }
    return true;
}

bool checkFlag(int x,int y, int h,char c1,char c2,char c3){
    for(int i=0;i<h;++i){
        if(board[x+i][y]!=c1) return false;
    }
    for(int i=0;i<h;++i){
        if(board[x+i+h][y]!=c2) return false;
    }
    for(int i=0;i<h;++i){
        if(board[x+i+h+h][y]!=c3) return false;
    }
    return true;
}
int widths[LIM][LIM];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            widths[i][j]=1;
            if(i&&board[i][j]==board[i-1][j]){
                widths[i][j]+=widths[i-1][j];
            }
        }
    }
    ll count=0;
    for(int i=0;i<n;++i){
        int currh=-1, curr=0;
        int ph=-1;
        for(int j=0;j<m;++j){
            currh=widths[i][j];
            if(!(currh*3<=(i+1)&&widths[i][j]==widths[i-currh][j]&&widths[i][j]<=widths[i-currh*2][j])){ph=-1; continue;}
            if(currh==ph&&board[i][j-1]==board[i][j]&&board[i-currh][j-1]==board[i-currh][j]&&board[i-currh*2][j-1]==board[i-currh*2][j]){
                curr++;
                
            }
            else{
                curr=1;
            }
            ph=currh;
            count+=curr;
        }
    }
    cout<<count;
    return 0;
}
