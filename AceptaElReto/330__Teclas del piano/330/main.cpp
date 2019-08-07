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
int keys[85];
int main() {
    ios::sync_with_stdio(false);
    int length;
    string s;
    int i;
    int j;
    while(cin>>length&&length){
        for(i=0;i<85;++i) keys[i]=0;
        for(i=0;i<length;++i){
            cin>>s;
            int pos;
            pos=(s[s.length()-1]-'0'-1)*12;
            switch(s[0]){
                case 'D':{
                    if(s[s.length()-2]=='b') pos--;
                    else if(s[s.length()-2]=='#') pos++;
                    break;
                }
                case 'R':{
                    if(s[s.length()-2]=='b') pos++;
                    else if(s[s.length()-2]=='#') pos+=3;
                    else pos+=2;
                    break;
                }
                case 'M':{
                    if(s[s.length()-2]=='b') pos+=3;
                    else if(s[s.length()-2]=='#') pos+=5;
                    else pos+=4;
                    break;
                }
                case 'F':{
                    if(s[s.length()-2]=='b') pos+=4;
                    else if(s[s.length()-2]=='#') pos+=6;
                    else pos+=5;
                    break;
                }
                case 'S':{
                    if(s[1]=='o'){
                        if(s[s.length()-2]=='b') pos+=6;
                        else if(s[s.length()-2]=='#') pos+=8;
                        else pos+=7;
                        break;
                    }
                    else{
                        if(s[s.length()-2]=='b') pos+=10;
                        else if(s[s.length()-2]=='#') pos+=12;
                        else pos+=11;
                        break;
                    }
                    
                }
                case 'L':{
                    if(s[s.length()-2]=='b') pos+=8;
                    else if(s[s.length()-2]=='#') pos+=10;
                    else pos+=9;
                    break;
                }
            }
            keys[pos]++;
        }
        for(i=0;i<85;++i){if(keys[i])break;}
        for(j=84;j>=0;--j){if(keys[j])break;}
        for(;i<j;i++){
            cout<<keys[i]<<" ";
        }
        cout<<keys[j]<<"\n";
    }
    return 0;
}

