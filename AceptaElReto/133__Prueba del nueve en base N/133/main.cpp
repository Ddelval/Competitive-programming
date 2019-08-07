// AceptaElReto 133:  Prueba del nueve en base N
//
//  main.cpp
//  133
//
//  Created by David del Val on 02/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int base;
int mod(string s){
    char c;
    long addition=0;
    for(int i=0;i<s.length();i++){
        c=s[i];
        if(c>='A'){
            addition+=(10+c-'A');
        }
        else{
            addition+=(c-'0');
        }
    }
    return addition%(base-1);
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int number;
    string divident, divisor, quotient, reminder;
    cin>>number;
    for(int i=0;i<number;i++){
        cin>>base>>divident>>divisor>>quotient>>reminder;
        if(mod(divident)==(mod(reminder)+(mod(quotient)*mod(divisor)))%(base-1)){
            cout<<"POSIBLEMENTE CORRECTO\n";
        }
        else{
            cout<<"INCORRECTO\n";
        }
    }
    return 0;
}
