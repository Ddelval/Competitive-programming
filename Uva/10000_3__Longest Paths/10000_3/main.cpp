// UVa Online Judge 10000: Longest_Paths
//
//  main.cpp
//  10000_3
//
//  Created by David del Val on 29/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,s;
    int finals;
    int finalm;
    int out;
    int count=1;
    int arg0,arg1;
    int vec[102];
    int sel;
    int min;
    while(true){
        int ady[102][102]={0};
        int marc[102]={0};
        cin>>n;
        if(!n){
            break;
        }
        cin>>s;
        s--;
        finals=s;
        cin>>arg0>>arg1;
        while(arg0||arg1){
            ady[arg0-1][arg1-1]=-1;
            cin>>arg0>>arg1;
        }
        for(int i=0;i<n;i++){
            if(i==s){
                vec[i]=0;
            }
            else{
                vec[i]=numeric_limits<int>::max();
            }
        }
        sel=s;
        while(true){
            for(int i=0;i<n;i++){
                if(ady[s][i]){
                    //It is not processed but it has a path
                    if(vec[s]+ady[s][i]<vec[i]){
                        vec[i]=vec[s]+ady[s][i];
                        marc[i]=0;
                    }
                   
                }
            }
            marc[s]=1;
            min=0;
            s=-1;
            for(int i=0;i<n;i++){
                if(!marc[i]&&vec[i]<min){
                    min=vec[i];
                    s=i;
                }
            }
            if(s==-1){
                finalm=0;
                out=finals;
                for(int i=0;i<n;i++){
                    if(finalm>vec[i]){
                        finalm=vec[i];
                        out = i;
                    }
                    
                }
                
                cout<<"Case "<<count<<": The longest path from "<<finals+1<<" has length "<<(-1*finalm)<<", finishing at "<<out+1<<"."<<endl<<endl;
                count++;
                break;
            }
        }
        
        
        
    }
    return 0;
}
