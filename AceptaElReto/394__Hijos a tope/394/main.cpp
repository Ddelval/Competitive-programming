// AceptaElReto 394:  Hijos a tope
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
string inputline;
int cursor;
long maxim;
long evaluate(){
    long a;
    if(inputline[cursor]=='0'){
        cursor++;
        return 0;
    }
    else if(inputline[cursor]=='1'){
        cursor++;
        evaluate();
        return 0;
    }
    else{
        cursor++;
        a=1+min(evaluate(),evaluate());
        if(a>maxim){
            maxim=a;
        }
        return a;
    }
    
    
    
}
int main() {
    ios::sync_with_stdio(false);
    int len;
    long out;
    string s;
    cin>>len;
    getline(cin,inputline);
    for(int i=0;i<len;i++){
        getline(cin,s);
        maxim=0;
        inputline.clear();
        for(int i=0;i<s.length();i+=2){
            inputline.push_back(s[i]);
        }
        cursor =0;
        out=evaluate();
        if(out<maxim){
            out=maxim;
        }
        cout<<out<<"\n";
    }
    return 0;
}

