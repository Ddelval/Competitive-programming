// UVa Online Judge 112: Tree Summing
//
//  main.cpp
//  0112
//
//  Created by David del Val on 02/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct node{
    vector<node> children;
    bool isroot;
    bool isleeave;
    int weight;
};
queue<node>toadd;
queue<int>finalise;
int findsplit(string res){
    int i;
    int appearsO=0,appearsC=0;
    for(i=0;i<res.length();i++){
        if(res[i]=='('){
            appearsO++;
        }
        else if(res[i]==')'){
            appearsC++;
        }
        if(appearsC==appearsO){
            break;
        }
    }
    return i;
}
void input(string s){
    if(s.length()==0){
        
    }else{
        int par =(int)count(s.begin(),s.end(),'(');
        if (par>2){
            node n;
            int index=(int)s.find('(');
            string res = s.substr(index);
            int i=findsplit(res);
            int weight =stoi(s.substr(0,(s.find('('))+1));
            string res1=res.substr(1,i-1);
            input(res1);
            for(int i=0;i<toadd.size();i++){
                n.children.push_back(toadd.front());
                toadd.pop();
            }
            res1=res.substr(i+2,res.size()-i-2-1);
            input (res1);
            for(int i=0;i<toadd.size();i++){
                n.children.push_back(toadd.front());
                toadd.pop();
            }
            n.isroot=false;
            n.isleeave=false;
            n.weight=weight;
            toadd.push(n);
            
        }
        
        else{
            node n;
            n.weight=stoi(s.substr(0,s.find('(')));
            n.isroot=false;
            n.isleeave=true;
            toadd.push(n);
            
        }
    }
    
    
    
}
int main(int argc, const char * argv[]) {
    string data,tmp;
    int appearsO,appearsC;
    while (getline(cin,data)){
        while(finalise.size()>0){
            finalise.pop();
        }
        while(toadd.size()>0){
            toadd.pop();
        }
        while(true){
            //Check for parenthesis
            appearsO=(int)count(data.begin(),data.end(),'(');
            appearsC=(int)count(data.begin(),data.end(),')');
            if(appearsO==appearsC){
                break;
            }
            getline(cin,tmp);
            data.append(tmp);
        }
        std::string::iterator end_pos = std::remove(data.begin(), data.end(), ' ');
        data.erase(end_pos, data.end());
        int weight =stoi(data.substr(0,(data.find('('))));
        data=data.substr((data.find('(')+1),data.size()-2-data.find('('));
        input(data);
        
        while(true){
            if(toadd.size()==0){
                break;}
            node n = toadd.front();
            if(n.isleeave){
                finalise.push(n.weight);
            }
            toadd.pop();
            int constant=(int)n.children.size();
            for(int i=0;i<constant;i++){
                node a = n.children.back();
                a.weight+=n.weight;
                toadd.push(a);
                n.children.pop_back();
                
            }
            
        }
        while(finalise.size()>0){
            if(finalise.front()==weight){
                break;
            }
            finalise.pop();
        }
        if(finalise.size()>0){
            cout<<"yes"<<endl;
            
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
