//
//  main.cpp
//  125
//
//  Created by David del Val on 15/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int i,num;
    int n1;
    string input,aux;
    cin>>input;
    i=input.length();
    if(i%2){
        //continue;
    }
    num=stoi(input);
    switch (i){
        case 2:{
            if(stoi(input.substr(0,2))*stoi(input.substr(2,2))==num){
                //Si
            }
            else{
                //No
            }
            break;
        }
        case 4:{
            n1=input[0]*10+input[1]*10;
            if(n1%num){
                
            }
            
            break;
        }
        case 6:{
            
            break;
        }
        case 8:{
            
            break;
        }

    }
    return 0;
}
