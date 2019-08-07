// UVa Online Judge 10000: Longest_Paths
//
//  main.cpp
//  10000_2
//
//  Created by David del Val on 27/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int s,n,arg1,arg2,maxlength,finalpos,i=0,y,w,count=1;;
    int ady[102][102]={0};
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        cin>>s;
        cin>>arg1>>arg2;
        while(arg1&&arg2){
            ady[arg1-1][arg2-1]=1;
            cin>>arg1>>arg2;
        }
        
        for(i=0;i<n;i++){
            for(w=0;w<n;w++){
                for(y=0;y<n;y++){
                    if(w==i||y==i||y==w){
                        
                    }else if(ady[w][i]&ady[i][y]){
                        ady[w][y]=ady[w][i]+ady[i][y];
                    }
                }
            }
        }
        maxlength=0;
        finalpos=n;
        for(int u=0;u<n;u++){
            if(ady[s-1][u]>maxlength){
                maxlength=ady[s-1][u];
                finalpos=u;
            }
        }
        cout<<"Case "<<count<<": The longest path from "<<s<<" has length "<<maxlength<<", finishing at "<<finalpos+1<<"."<<endl;
        
        count++;
    }
    
    
    
    
    return 0;
}
