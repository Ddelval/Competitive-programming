//
//  main.cpp
//  0107
//
//  Created by David del Val on 27/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int cats;
    int height;
    int heightaux;
    int counter;
    int totalheight=0;
    int totalcats=0;
    int sqr;
    bool flag = true;
    
    cin>>height>>cats;
    while(height!=0||cats!=0){
        flag = true;
        totalheight=0;
        totalcats=0;
        if(height==1){
            cout<<0<<" "<<1<<endl;
            cin>>height>>cats;
            continue;
        }
        sqr = (int)sqrt(height);
        sqr+=2;
        for(int i=2;i<=sqr;i++){
            if(!(height%i)){
                heightaux=height;
                counter=0;
                while(heightaux!=1){
                    if(!(heightaux%i)){
                        heightaux=heightaux/i;
                        counter++;
                    }
                    else{
                        break;
                    }
                }
                if(heightaux==1){
                    if(cats==pow((i-1),counter)){
                        for(int j=0;j<counter;j++){
                            totalcats+=pow(i-1,j);
                        }
                        for(int j=0;j<=counter;j++){
                            totalheight+= (pow(i-1, j))*(height/(pow(i, j)));
                        }
                        
                        cout<<totalcats<<" "<<totalheight<<endl;
                        flag=false;
                    }
                    
                    
                }
                
                
            }
        }
        if(flag){
            int i=height;
            /*if(!(height%i)){
                heightaux=height;
                counter=0;
                while(heightaux!=1){
                    if(!(heightaux%i)){
                        heightaux=heightaux/i;
                        counter++;
                    }
                    else{
                        break;
                    }
                }*/
            counter=1;
            
                    if(cats==pow((i-1),counter)){
                        for(int j=0;j<counter;j++){
                            totalcats+=pow(i-1,j);
                        }
                        for(int j=0;j<=counter;j++){
                            totalheight+= (pow(i-1, j))*(height/(pow(i, j)));
                        }
                        
                        cout<<totalcats<<" "<<totalheight<<endl;
                        
                    }
            
        }
        cin>>height>>cats;
    }
    
    return 0;
}
