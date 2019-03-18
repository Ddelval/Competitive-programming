#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
char matrix[100][100];
int main() {
    ios::sync_with_stdio(false);
    string input;
    string out;
    int x, y,i,j;
    int max_x;
    while(getline(cin,input)){
        x=y=0;
        max_x=0;
        for(i=0;i<100;++i){
            for(j=0;j<100;++j){
                matrix[i][j]=' ';
            }
        }
        for(i=0;i<input.length();++i){
            switch(input[i]){
                case 'I':{
                    if(x>max_x){
                        max_x=x;
                    }
                    matrix[x][y]='_';
                    y++;
                    break;
                }
                case 'S':{
                    if(x>max_x){
                        max_x=x;
                    }
                    matrix[x][y]='/';
                    y++;
                    x++;
                    
                    break;
                }
                case 'B':{
                    x--;
                    matrix[x][y]='\\';
                    y++;
                    break;
                }
                    
            }
        }
        out="";
        for(j=0;j<input.length();++j){
            out+='#';
        }
        out+="##\n";
        for(i=max_x;i>=0;i--){
            out+='#';
            for(j=0;j<input.length();++j){
                out+=matrix[i][j];
            }
            out+="#\n";
        }
        for(j=0;j<input.length();++j){
            out+='#';
        }
        out+="##\n";
        cout<<out;
    }
    return 0;
}

