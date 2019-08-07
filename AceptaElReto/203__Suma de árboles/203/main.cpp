// AceptaElReto 203:  Suma de árboles
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
string s1;
string s2;
string out;
string aux,aux2;
void readfrom1(){
    if(s1[0]=='-'){
        s1=s1.substr(3);
        out.append("-1 ");
    }
    else{
        aux=s1.substr(0,s1.find(' '));
        out+=aux;
        out.append(" ");
        s1=s1.substr(aux.length()+1);
        readfrom1();
        readfrom1();
    }
}

void readfrom2(){
    if(s2[0]=='-'){
        s2=s2.substr(3);
        out.append("-1 ");
    }
    else{
        aux=s2.substr(0,s2.find(' '));
        out+=aux;
        out.append(" ");
        s2=s2.substr(aux.length()+1);
        readfrom2();
        readfrom2();
    }
}
void readfromBoth(){
    if(s1[0]!='-'&&s2[0]!='-'){
        aux=s1.substr(0,s1.find(' '));
        s1=s1.substr(aux.length()+1);
        aux2=s2.substr(0,s2.find(' '));
        s2=s2.substr(aux2.length()+1);
        out+=to_string((stoi(aux)+stoi(aux2)));
        out.append(" ");
        readfromBoth();
        readfromBoth();
    }
    else if(s1[0]!='-'&&s2[0]=='-'){
        aux=s1.substr(0,s1.find(' '));
        out+=aux;
        out.append(" ");
        s1=s1.substr(aux.length()+1);
        s2=s2.substr(3);
        readfrom1();
        readfrom1();
    }
    else if(s1[0]=='-'&&s2[0]!='-'){
        aux=s2.substr(0,s2.find(' '));
        out+=aux;
        out.append(" ");
        s2=s2.substr(aux.length()+1);
        s1=s1.substr(3);
        readfrom2();
        readfrom2();
    }
    else{
        s2=s2.substr(3);
        s1=s1.substr(3);
        out.append("-1 ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    while(getline(cin,s1)&&getline(cin,s2)){
        if(s1=="-1"&&s2=="-1"){
            break;
        }
        s1.append(" ");
        s2.append(" ");
        out.clear();
        readfromBoth();
        cout<<out.substr(0,out.length()-1)<<"\n";
        
    }
    return 0;
}

