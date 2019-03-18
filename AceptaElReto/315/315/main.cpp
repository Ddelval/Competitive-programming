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
int board[51][51];
bool discovered[51][51];
int width,height;
/*
void coutboard(){
    int i,j;
    for(i=0;i<height;++i){
        for(j=0;j<width;++j){
            printf("%3d",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 */
void discoverround(int x,int y){
    discovered[x][y]=true;
    if(board[x][y]){
        return;
    }
    if(x!=0){
        if(!discovered[x-1][y]){
            discoverround(x-1, y);
        }
    }
    if(y!=0){
        if(!discovered[x][y-1]){
            discoverround(x, y-1);
        }
    }
    if(x!=height-1){
        if(!discovered[x+1][y]){
            discoverround(x+1, y);
        }
    }
    if(y!=width-1){
        if(!discovered[x][y+1]){
            discoverround(x, y+1);
        }
    }
    //Diagonals
    if(x!=0&&y!=0){
        if(!discovered[x-1][y-1]){
            discoverround(x-1, y-1);
        }
    }
    if(y!=0&&x!=height-1){
        if(!discovered[x+1][y-1]){
            discoverround(x+1, y-1);
        }
    }
    if(x!=0&&y!=width-1){
        if(!discovered[x-1][y+1]){
            discoverround(x-1, y+1);
        }
    }
    if(x!=height-1&&y!=width-1){
        if(!discovered[x+1][y+1]){
            discoverround(x+1, y+1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    char c;
    int i,j;
    int x,y;
    int cas;
    int ady;
    bool gamov;
    height=0;
    width=0;
    while(cin>>height>>width){
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                discovered[i][j]=0;
                board[i][j]=0;
            }
        }
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                cin>>c;
                if(c=='*'){
                    board[i][j]=-1;
                }
                
            }
        }
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                if(board[i][j]==-1){
                    continue;
                }
                ady=0;
                //Cross-adjacency
                if(i!=0&&board[i-1][j]==-1){
                    ady++;
                }
                if(j!=0&&board[i][j-1]==-1){
                    ady++;
                }
                if(i!=height-1&&board[i+1][j]==-1){
                    ady++;
                }
                if(j!=width-1&&board[i][j+1]==-1){
                    ady++;
                }
                //Diagonals
                if(i!=0&&j!=0&&board[i-1][j-1]==-1){
                    ady++;
                }
                if(j!=0&&i!=height-1&&board[i+1][j-1]==-1){
                    ady++;
                }
                if(i!=0&&j!=width-1&&board[i-1][j+1]==-1){
                    ady++;
                }
                if(i!=height-1&&j!=width-1&&board[i+1][j+1]==-1){
                    ady++;
                }
                board[i][j]=ady;
                
            }
        }
        cin>>cas;
        gamov=false;
        for(i=0;i<cas;++i){
            cin>>x>>y;
            x--;
            y--;
            if(discovered[x][y]){
                continue;
            }
            if(!gamov){
                if(board[x][y]==-1){
                    gamov=true;
                }
                else if(board[x][y]){
                    discovered[x][y]=true;
                }
                else{
                    discoverround(x, y);
                }
            }
        }
        if(gamov){
            cout<<"GAME OVER\n";
            continue;
        }
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                if(discovered[i][j]){
                    if(board[i][j]){
                       cout<<board[i][j];
                    }
                    else{
                        cout<<"-";
                    }
                    
                }
                else{
                    cout<<"X";
                }
                
            }
            cout<<"\n";
        }
        
        
        
    }
    return 0;
}

