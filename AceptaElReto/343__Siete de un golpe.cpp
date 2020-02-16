// AceptaElReto 343:  Siete de un golpe
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
#define mp(x,y) make_pair(x,y)
using namespace std;
int board[1000][1000];
int height,width;
int mh,mw;
int main() {
    ios::sync_with_stdio(false);
    int sum;
    int o[8];
    char in;
    int i,j,w;
    while(cin>>width>>height>>mw>>mh && width){
        for(i=0;i<height;++i){
            sum=0;
            for(int j=0;j<width;++j){
                cin>>in;
                if(in=='X') sum++;
                board[i][j]=sum;
            }
        }
        for(i=0;i<8;++i){
            o[i]=0;
        }
        for(i=0;i<=height-mh;++i){
            for(j=0;j<=width-mw;++j){
                sum=0;
                for(w=0;w<mh;++w){
                    if(j>0)sum+=board[i+w][j+mw-1]-board[i+w][j-1];
                    else sum+=board[i+w][j+mw-1];
                    
                }
                if(sum<=7){
                    o[sum]++;
                }
            }
        }
        for(i=0;i<7;++i){
            cout<<o[i]<<" ";
        }
        cout<<o[7]<<"\n";
    }
    return 0;
}

