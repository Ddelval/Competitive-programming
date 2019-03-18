//
//  main.cpp
//  389
//
//  Created by David del Val on 15/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//
/*
 #include <iostream>
 #include <map>
 #include <stdio.h>
 #include <set>
 #include <vector>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 using namespace std;
 
 typedef pair<int,bool> ib;
 char s1[9],s2[9],s3[9];
 unsigned long l1,l2,l3;
 set<char> abc;
 char c;
 map<char,int> data;
 vector<ib> choose;
 
 bool check(){
 int a1=0,a2=0,a3=0;
 int i;
 if(!data.at(s1[0])){
 return false;
 }
 if(!data.at(s2[0])){
 return false;
 }
 if(!data.at(s3[0])){
 return false;
 }
 for(i=0;i<l1;++i){
 a1+=pow(10,i)*data.at(s1[l1-1-i]);
 }
 for(i=0;i<l2;++i){
 a2+=pow(10,i)*data.at(s2[l2-1-i]);
 }
 for(i=0;i<l3;++i){
 a3+=pow(10,i)*data.at(s3[l3-1-i]);
 }
 if(c=='+'){
 if(a1+a2==a3){
 return true;
 }
 }
 else{
 if(a1*a2==a3){
 return true;
 }
 }
 return false;
 
 }
 
 
 
 bool assign(int index){
 bool b;
 char a;
 if(index==abc.size()){
 b=check();
 if(b){
 return true;
 }
 return false;
 }
 set<char>::iterator it = abc.begin();
 advance(it,index);
 a=*it;
 for(int i=0;i<choose.size();++i){
 if(!(choose[i].second)){
 data.at(a)=choose[i].first;
 choose[i].second=true;
 b=assign(index+1);
 choose[i].second=false;
 if(b){
 return true;
 }
 }
 
 
 
 }
 return false;
 
 
 }
 
 int main(int argc, const char * argv[]) {
 
 int i;
 
 while(scanf("%s %c %s = %s",s1,&c,s2,s3)){
 l1=strlen(s1);
 l2=strlen(s2);
 l3=strlen(s3);
 for(i=0;i<l1;++i){
 abc.insert(s1[i]);
 }
 for(i=0;i<l2;++i){
 abc.insert(s2[i]);
 }
 for(i=0;i<l3;++i){
 abc.insert(s3[i]);
 }
 for(set<char>::iterator i = abc.begin();i!=abc.end();i++){
 data.insert(make_pair(*(i),0));
 }
 for(i=0;i<10;i++){
 choose.push_back(make_pair(i,false));
 }
 assign(0);
 for(auto it = data.begin();it!=data.end();it++){
 cout<<(*it).first<<" "<<(*it).second<<"\n";
 }
 }
 
 
 return 0;
 }
 */

#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

string s1, s2, s3,operador,trash;
char table [3][8];
map<char,int> equiv;
bool taken[10];

bool checksum(int limcol){
    int carry=0;
    int add;
    for(int i=0;i<=limcol;++i){
        add=carry+equiv[table[0][i]]+equiv[table[1][i]];
        carry=add/10;
        add%=10;
        if(equiv[table[2][i]]==-1){
            equiv[table[2][i]]=add;
        }
        else{
            if(equiv[table[2][i]]!=add){
                return false;
            }
        }
    }
    return true;
}
bool find(int x,int y){
    
    if(x==2){
        if(checksum(y)){
            find(0,y+1);
        }
        else{
            return false;
        }
        
    }
    else if(equiv[table[x][y]]==-1){
        for(int i=0;i<10;++i){
            if(!taken[i]){
                equiv[table[x][y]]=i;
                taken[i]=true;
                if(find(x+1,y)){
                    return true;
                }
                taken[i]=false;
            }
        }
        
    }
    else{
        if(find(x+1,y)){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    int i,j;
    cin>>s1>>operador>>s2>>trash>>s3;
    for(i=0;i<8;++i){
        table[0][i]='-';
        table[1][i]='-';
        table[2][i]='-';
    }
    j=0;
    for(i=s1.length()-1;i>=0;--i){//inicializacion maps
        table[0][j]=s1[i];
        if(equiv.find(s1[i])==equiv.end()){
            equiv[s1[i]]=-1;
        }
        j++;
    }
    j=0;
    for(i=s2.length()-1;i>=0;--i){
        table[1][j]=s2[i];
        if(equiv.find(s2[i])==equiv.end()){
            equiv[s2[i]]=-1;
        }
        j++;
    }
    j=0;
    for(i=s2.length()-1;i>=0;--i){
        table[2][j]=s3[i];
        if(equiv.find(s3[i])==equiv.end()){
            equiv[s3[i]]=-1;
        }
        j++;
    }
    find(0,0);
    cout<<"y";
    
    return 0;
}

