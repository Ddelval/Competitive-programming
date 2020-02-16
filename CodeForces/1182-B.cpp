//
//  main.cpp
//  1182-B
//
//  Created by David del Val on 11/06/2019.
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
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
bool tab[500][500];
int main(){
    ios::sync_with_stdio(false);
    int h,w;
    char c;
    while(cin>>h>>w){
        int x1,x2,y1,y2;
        int col,row;
        x1=x2=y1=y2=col=row=-1;
        for(int j=0;j<h;j++){
            for(int i=0;i<w;++i){
                cin>>c;
                if(c=='*'){
                    tab[j][i]=true;
                    if(col==-1){
                        //We found the first *
                        col=i;
                        y1=j;
                    }
                    else{
                        if(i==col){
                            //We keep going down
                        }
                        else if(row==-1){
                            //We found the horizontal line
                            row=j;
                            x1=i;
                        }
                    }
                }
                else{
                    tab[j][i]=false;
                }
            }
        }
        if(!tab[row][col]){
            cout<<"NO\n";
            continue;
        }
        if(col==-1||y1==-1||x1==-1||row==-1){
            cout<<"NO\n";
            continue;
        }
        for(int i=x1;i<w;++i){
            if(!tab[row][i]){
                x2=i-1;
                break;
            }
        }
        if(x2==-1){
            x2=w-1;
        }
        for(int i=y1;i<h;++i){
            if(!tab[i][col]){
                y2=i-1;
                break;
            }
        }
        if(y2==-1){
            y2=h-1;
        }
        if(x2<=col||y2<=row){
            cout<<"NO\n";
            continue;
        }
        bool exit=false;
        for(int j=0;j<h;j++){
            for(int i=0;i<w;++i){
                if(tab[j][i]){
                    if(j!=row &&i !=col){
                        cout<<"NO";
                        exit=true;
                        break;
                    }
                    if(j==row&&(i<x1||i>x2)){
                        cout<<"NO";
                        exit=true;
                        break;
                    }
                    if(i==col&&(j<y1||j>y2)){
                        cout<<"NO";
                        exit=true;
                        break;
                    }
                }
            }
            if(exit)break;
        }
        if(exit)continue;
        cout<<"YES\n";
    }
    
    return 0;
}

