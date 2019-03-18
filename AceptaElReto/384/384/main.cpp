//
//  main.cpp
//  384
//
//  Created by David del Val on 25/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    //Use an array to avoid emptying the vector every time
    pair<int,int> target[500000];
    int length;
    int num;
    int arrayindex; //This is the cursor that we will be using to increase the position in the array
    bool bad;
    int i;
    bool in;
    while(cin>>length){
        //Initialization
        bad=false;
        cin>>num;
        arrayindex=0;
        target[arrayindex]=make_pair(num,num);
        
        for(i=1;i<length;i++){
            cin>>num;
            //Check if the number is in an interval
            //The magic part of this cod is &&target[i].first. For some reason, that makes a huge different (TLE to 0.35)
            in=false;
            for(int i=(int)arrayindex;i>=0&&target[i].first<num;i--){
                if(num>target[i].first&&num<target[i].second){
                    in=true;
                }
            }
            //If the number is in an interval, exit
            if(in){
                bad=true;
                break;
            }
            
            //Check if we have found a new minimum
            if(num<target[arrayindex].first){
                //If the current interval has lenght 0, we dont need to create a new one. We will change the one we have since it is useless.
                if(target[arrayindex].first==target[arrayindex].second){
                    target[arrayindex].first=num;
                    target[arrayindex].second=num;
                }
                else{
                    arrayindex++;
                    target[arrayindex]=make_pair(num,num);
                }
                
            }
            
            //If the new value is greater than the current maximum, make the interval bigger
            else{
                if(target[arrayindex].second<num){
                    target[arrayindex].second=num;
                }
                
                
            }
        }
        //Clean the buffer
        for(i++;i<length;i++){
            cin>>num;
        }
        //Output
        if(bad){
            cout<<"ELEGIR OTRA\n";
        }
        else{
            cout<<"SIEMPRE PREMIO\n";
        }
    }
    
    return 0;
}
