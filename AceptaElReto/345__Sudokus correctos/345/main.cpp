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
int board[9][9];
int cont,tmpx,tmpy;
bool b[9];
bool all;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    while(cas--){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                cin>>board[i][j];
            }
        }
        //Check rows
        all=true;
        for(int i=0;i<9;++i){
            memset(b,false,9);
            cont=0;
            for(int j=0;j<9;++j){
                if(!b[board[i][j]-1]){
                    cont++;
                    b[board[i][j]-1]=true;
                }
            }
            if(cont!=9){
                all=false;
                break;
            }
        }
        if(!all){
            cout<<"NO\n";
            continue;
        }
        //Check columns
        for(int i=0;i<9;++i){
            memset(b,false,9);
            cont=0;
            for(int j=0;j<9;++j){
                if(!b[board[j][i]-1]){
                    cont++;
                    b[board[j][i]-1]=true;
                }
            }
            if(cont!=9){
                all=false;
                break;
            }
        }
        if(!all){
            cout<<"NO\n";
            continue;
        }
        //Check sections
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                memset(b,false,9);
                cont=0;
                tmpx=3*i;
                tmpy=3*j;
                for(int w=0;w<9;++w){
                    if(!b[board[tmpx+w/3][tmpy+w%3]-1]){
                        cont++;
                        b[board[tmpx+w/3][tmpy+w%3]-1]=true;
                    }
                }
                if(cont!=9){
                    all=false;
                    break;
                }
            }
        }
        if(!all){
            cout<<"NO\n";
            continue;
        }
        cout<<"SI\n";
    }
    return 0;
}

