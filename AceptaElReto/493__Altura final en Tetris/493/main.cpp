// AceptaElReto 493:  Altura final en Tetris
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
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";
int pieces[4][7][4]={
    {
        {1,1,1,1},{2,1,1,0},{1,1,2,0},{2,2,0,0},{1,2,2,0},{1,2,1,0},{2,2,1,0}
    },
    {
        {4,0,0,0},{1,3,0,0},{3,3,0,0},{2,2,0,0},{3,2,0,0},{2,3,0,0},{2,3,0,0}
    },
    {
        {1,1,1,1},{2,2,2,0},{2,2,2,0},{2,2,0,0},{1,2,2,0},{2,2,2,0},{2,2,1,0}
    },
    {
        {4,0,0,0},{3,3,0,0},{3,1,0,0},{2,2,0,0},{3,2,0,0},{3,2,0,0},{2,3,0,0}
    }
};
int gap[4][7][4]={
    {
        {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,0},{1,0,0,0}
    },
    {
        {0,0,0,0},{0,0,0,0},{2,0,0,0},{0,0,0,0},{1,0,0,0},{1,0,0,0},{0,1,0,0}
    },
    {
        {0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,1,0},{1,0,1,0},{1,0,0,0}
    },
    {
        {0,0,0,0},{0,2,0,0},{0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{0,1,0,0}
    },
    
};
int h[4][7]={
     {1,2,2,2,2,2,2},{4,3,3,2,3,2,2},{1,2,2,2,2,2,2},{1,3,3,2,3,3,2}
};
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int heights[100];
int main(){
    ios::sync_with_stdio(false);
    int col, piez;
    int piezheight;
    int a,r,p;
    int lfin;
    int temp;
    while(cin>>col>>piez&&piez){
        for(int i=0;i<col;i++){
            heights[i]=0;
        }
        for(int i=0;i<piez;++i){
            cin>>a>>r>>p;
            switch(r){
                case 0:{
                    r=0;
                    break;
                }
                case 90:{
                    r=1;
                    break;
                }
                case 180:{
                    r=2;
                    break;
                }
                case 270:{
                    r=3;
                    break;
                }
            }
            lfin=0;
            p--;
            piezheight=0;
            //echo_array(9,heights);
            for(int i=0;i<4;++i){
                if(pieces[r][a-1][i])temp=heights[p+i]+h[r][a-1]-gap[r][a-1][i];
                if(temp>lfin){
                    lfin=temp;
                }
            }
            for(int i=0;i<4;++i){
                if(pieces[r][a-1][i])heights[p+i]=lfin-(h[r][a-1]-pieces[r][a-1][i]);
            }
            
        }
        cout<<heights[0];
        for(int i=1;i<col;i++){
            cout<<" "<<heights[i];
        }
        cout<<"\n";
    }
    
    return 0;
}

