// AceptaElReto 410:  Dígitos saltarines
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

int main() {
    ios::sync_with_stdio(false);
    int cas;
    int cursor,visited;
    int l;
    string s;
    getline(cin,s);
    cas=stoi(s);
    
    for(int i=0;i<cas;++i){
        cin>>s;
        visited=0;
        cursor=0;
        l=(int)s.length();
        do{
            cursor+=(s[cursor]-'0');
            cursor%=l;
            visited++;
        }while(cursor!=0&&visited<l);
        if(cursor==0&&visited==l){
            cout<<"SALTARINES\n";
        }
        else{
            cout<<"NORMALES\n";
        }
    }
    return 0;
}

