// UVa Online Judge 109: SCUD Busters
// 
//  main.cpp
//  0109
//
//  Created by David del Val on 27/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int map [41][41]={};
    int kingdomplaces [10][10][2]={-1};
    int kingdomnum=1;
    int kingdomlength;
    int x,y;
    int countplace=0;
    for(int i=0;i<41;i++){
        for(int j=0;j<41;j++){
            map[i][j]=-1;
        }
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            kingdomplaces[i][j][0]=-1;
            kingdomplaces[i][j][1]=-1;
        }
    }
    
    
    
    
    
    cin>>kingdomlength;
    while(kingdomlength!=-1){
        countplace=0;
        for(int i=0;i<kingdomlength;i++){
            cin>>x>>y;
            map[x][y]=kingdomnum;
            kingdomplaces[kingdomnum][countplace][0]=x;
            kingdomplaces[kingdomnum][countplace][1]=y;
            countplace++;
        }
        cin>>kingdomlength;
        kingdomnum++;
    }
    while(cin>>x>>y){
        map[x][y]=9;
    }
    
    
    
    for(int i=0;i<41;i++){
        for(int j=0;j<41;j++){
            if (map[i][j]==-1) {
                cout<<"  ";
            }
            else{
                
            cout<<map[i][j]<<" ";
            }
        }
        cout<<endl;
    }
   
    
    for(int i=0;i<kingdomnum;i++){
        
        cout<<i<<": ";
        for(int j=0;j<10;j++){
            
            if(kingdomplaces[i+1][j][1]!=-1){
                cout<<"("<<kingdomplaces[i+1][j][0]<<" , "<<kingdomplaces[i+1][j][1]<<")"<<"  ";
            }
            
                
        }
        cout<<endl;
        
    }
    /*
    int a=0;
    for(int i=1;i<10;i++){
        a+=(kingdomplaces[1][i-1][0]*kingdomplaces[1][i][1]-kingdomplaces[1][i][0]*kingdomplaces[1][i-1][1]);
    }
    a=a/2;
    cout<<a;
    */
    return 0;
}
