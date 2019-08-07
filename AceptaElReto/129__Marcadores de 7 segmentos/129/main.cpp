// AceptaElReto 129:  Marcadores de 7 segmentos
//
//  main.cpp
//  129
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
//int v[11][7]={{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1},{0,0,0,0,0,0,0}};
int data[11][11]={
{0,4,3,3,4,3,2,3,1,2,6},
{4,0,5,3,2,5,6,1,5,4,2},
{3,5,0,2,5,4,3,4,2,3,5},
{3,3,2,0,3,2,3,2,2,1,5},
{4,2,5,3,0,3,4,3,3,2,4},
{3,5,4,2,3,0,1,4,2,1,5},
{2,6,3,3,4,1,0,5,1,2,6},
{3,1,4,2,3,4,5,0,4,3,3},
{1,5,2,2,3,2,1,4,0,1,7},
{2,4,3,1,2,1,2,3,1,0,6},
{6,2,5,5,4,5,6,3,7,6,0}};
/*void preprocess(){
    int diff;
    for(int i=0;i<11;i++){
        for(int j=0;j<i;j++){
            diff=0;
            for(int w=0;w<7;w++){
                if(v[i][w]!=v[j][w]){
                    diff++;
                }
            }
            data[i][j]=diff;
            data[j][i]=diff;
            
        }
        data[i][i]=0;
    }
}*/
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    //preprocess();
    /*for(int i=0;i<11;i++){
        cout<<"{";
        for(int j=0;j<11;j++){
            cout<<data[i][j]<<",";
        }
        cout<<"}\n";
    }*/
    
    int prevnum;
    int number;
    int a;
    long changes;
    cin>>number;
    while(number!=-1){
        a=0;
        changes=0;
        prevnum=10;
        while(number!=-1){
            changes+=data[prevnum][number];
            prevnum=number;
            a++;
            cin>>number;
        }
        changes+=data[prevnum][10];
        cout<<a*changes<<"\n";
        cin>>number;
    }
   return 0;
}
