//
//  main.cpp
//  392
//
//  Created by David del Val on 09/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num, cases;
    int index;
    int data[50][50]={0};
    int freespaces[50];
    int arg1,arg2;
    int y,flag;
    cin>>num;
    cin>>cases;
    while(1){
        if(num==0&&cases==0){
            break;
        }
        for(int i=0;i<num;i++){
            for (int j=0; j<num; j++) {
                data[i][j]=0;
            }
            data[i][i]=1;
            freespaces[i]=num-1;
        }
        for(int i=0;i<cases;i++){
            cin>>arg1;
            cin>>arg2;
            for(int i=0;i<num;i++){
                data[arg1-1][i]=1;
                if(!(data[i][arg2-1])){
                    data[i][arg2-1]=1;
                    freespaces[i]--;
                }
            }
            freespaces[arg1-1]=0;
        }
        while(1){
            for(y=0;y<num;y++){
                if(freespaces[y]==1){
                    index=0;
                    for(int j=0;j<num;j++){
                        if(!data[y][j]){
                            index=j;
                        }
                    }
                    for(int j=0;j<num;j++){
                        if(!data[j][index]){
                            freespaces[j]--;
                            data[j][index]=1;
                        }
                    }
                    
                    break;
                }
            }
            if(y==num){
                break;
            }
        }
        
        flag =0;
        for(int i=0;i<num;i++){
            if(freespaces[i]){
                flag=1;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"SI"<<endl;
        }
        
        
        
        
        
        
        cin>>num;
        cin>>cases;
    }
    return 0;
}
