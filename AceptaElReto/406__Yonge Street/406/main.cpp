#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
char street[200000];
int main() {
    ios::sync_with_stdio(false);
    string input,in;
    stringstream ss;
    int itr, sit;
    int count;
    int ileng;
    int inp;
    while(getline(cin,input)){
        //If we only have the line break in the input, get the input again.
        if(!input.length()){
            getline(cin,input);
        }
        else if(input.length()==1){
            if(input[0]=='.'){
                
            }
            else if(input[0]=='|'){
                
            }
            else if(input[0]>='A'&&input[0]<='Z'){
                
            }else if(input[0]>='a'&&input[0]<='z'){
                
            }
            else{
                getline(cin,input);
            }
        }

        itr=(int)input.length();
        sit=0;
        count=0;
        //Replace everything before the first '|' with dots since all those cars will go away
        for(itr--;true;itr--){
            if(itr<0||input[itr]=='|'){
                break;
            }
            count++;
        }
        for(;count>0;count--){
            street[sit]='.';
            sit++;
        }
        if(!(itr<0)){
            street[sit]='|';
            sit++;
        }
        
        while(1){
            //Keep sorting all the intervals between bars. First place the letters in the array and then add the dots that the counter has counted.
            for(--itr;true;--itr){
                if(itr<0||input[itr]=='|'){
                    break;
                }
                if(input[itr]!='.'){
                    street[sit]=input[itr];
                    sit++;
                }
                else{
                    count++;
                }
            }
            for(;count>0;count--){
                street[sit]='.';
                sit++;
            }
            if(itr<0){
                break;
            }
            street[sit]='|';
            sit++;
        }
        //Output
        getline(cin, in);
        stringstream ss(in);
        ss>>ileng;
        if(ileng){
            for(int i=0;i<ileng-1;i++){
                ss>>inp;
                cout<<street[input.length()-inp]<<" ";
            }
            ss>>inp;
            cout<<street[input.length()-inp]<<"\n";
        }
        
        
    }
    return 0;
}

