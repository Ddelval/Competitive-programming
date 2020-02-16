// AceptaElReto 132:  Las cartas del abuelo
//
//  main.cpp
//  132
//
//  Created by David del Val on 02/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int number,start,end;
    int low;
    string letter;
    int data[1000001];
    while(1){
        getline(cin,letter);
        if(letter==""){
            continue;
        }
        cin>>number;
        if(!number){
            return 0;
        }
        low=(int)letter.length();
        data[0]=0;
        for(int a=1;a<low;a++){
            if(letter[a-1]==letter[a]){
                data[a]=data[a-1];
            }
            else{
                data[a]=a;
            }
        }
        for(int i=0;i<number;i++){
            cin>>start>>end;
            
            if(data[start]==data[end]){
                cout<<"SI\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        cout<<"\n";
    }
    
    return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int number,start,end;
    vector<int>v_start;
    vector<int>v_end;
    int minimum,maximum;
    int low;
    string letter;
    int data[1000001];
    while(1){
        getline(cin,letter);
        if(letter==""){
            continue;
        }
        cin>>number;
        if(!number){
            return 0;
        }
        low=(int)letter.length();
        
        maximum=(int)letter.length();
        minimum=0;
        v_start.clear();
        v_end.clear();
        for(int i=0;i<number;i++){
            cin>>start>>end;
            v_start.push_back(start);
            v_end.push_back(end);
            if(start<minimum){
                minimum=start;
            }
            if(end>maximum){
                maximum=end;
            }
        }
        data[minimum]=0;
        for(int a=minimum+1;a<=maximum;a++){
            if(letter[a-1]==letter[a]){
                data[a]=data[a-1];
            }
            else{
                data[a]=a;
            }
        }
        for(int i=0;i<number;i++){
            if(data[v_start[i]]==data[v_end[i]]){
                cout<<"SI\n";
                
            }
            else{
                cout<<"NO\n";
            }
                
        
        }
        cout<<"\n";
    }
    
    return 0;
}
