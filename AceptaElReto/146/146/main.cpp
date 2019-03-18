//
//  main.cpp
//  146
//
//  Created by David del Val on 25/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int target;
    vector<int> numbers;
    int remaining;
    int counter;
    int j;
    cin>>target;
    while(target){
        numbers.clear();
        for(int i=1;i<=target;i++){
            numbers.push_back(i);
        }
        remaining=target;
        counter=0;
        for(int i=1;remaining>i;i++){
            counter=0;
            for(j=0;j<target;j++){
                if(numbers[j]){
                    numbers[j]=0;
                    remaining--;
                    break;
                }
            }
            for(j++;j<target;j++){
                if(numbers[j]){
                    counter++;
                }
                if(counter==i+1){
                    numbers[j]=0;
                    counter=0;
                    remaining--;
                }
            }
        }
        cout<<target<<":";
        for(int i=target-1;i>=0;i--){
            if(numbers[i]){
                cout<<" "<<i+1;
            }
        }
        cout<<"\n";
        cin>>target;
    }
    
    return 0;
}
