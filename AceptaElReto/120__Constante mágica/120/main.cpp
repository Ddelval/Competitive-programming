// AceptaElReto 120:  Constante mágica
//
//  main.cpp
//  120
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int data[100];
void preprocess(){
    for(int w=3;w<100;w+=2){
        int matrix[w][w];
        int counter=0;
        for(int a=0;a<w;a++){
            for(int b=0;b<w;b++){
                matrix[a][b]=0;
            }
        }
        int i,j;
        j=w/2;
        i=0;
        while(j!=0||i!=w-1){
            counter++;
            matrix[i][j]=1;
            if(i==0){
                j=j+1;
                i=w-1;
            }
            else if(j==w-1){
                j=0;
                i=i-1;
            }
            else if(matrix[i-1][j+1]!=0){
                i=i+1;
            }
            else{
                i=i-1;
                j=j+1;
            }
            
        }
        data[w]=counter;
    }
    
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    preprocess();
    data[1]=0;
    int n,k;
    cin>>n>>k;
    while(n||k){
        cout<<((data[n]+k+n)*(data[n]+k-1+n))/2-((data[n]+k)*(data[n]+k-1))/2<<"\n";
        cin>>n>>k;
    }
    return 0;
}
