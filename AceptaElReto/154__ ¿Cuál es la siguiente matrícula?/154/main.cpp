// AceptaElReto 154:  ¿Cuál es la siguiente matrícula?
//
//  main.cpp
//  154
//
//  Created by David del Val on 27/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;
char nextchar(char c){
    char a=c+1;
    if(a=='E'){
        a++;
    }
    if(a=='I'){
        a++;
    }
    if(a=='O'){
        a++;
    }
    if(a=='U'){
        a++;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char s[4];
    int n;
    while(cin>>n>>s&&(n!=9999||s[0]!='Z'||s[1]!='Z'||s[2]!='Z')){
        if(n!=9999){
            n++;
            printf("%04d %s\n",n,s);
            continue;
        }
        n=0;
        if(s[2]!='Z'){
            s[2]=nextchar(s[2]);
        }
        else{
            if(s[1]!='Z'){
                s[1]=nextchar(s[1]);
                s[2]='B';
            }
            else{
                s[0]=nextchar(s[0]);
                s[1]='B';
                s[2]='B';
            }
        }
        printf("%04d %s\n",n,s);

        
    }
    return 0;
}
