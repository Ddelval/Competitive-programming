// AceptaElReto 467:  Polisílaba es polisílaba
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
#define diff 'a'-'A'
using namespace std;
string s,s2;
int main() {
    ios::sync_with_stdio(false);
    int cas,i;
    cin>>cas;
    for(int j=0;j<cas;++j){
        cin>>s>>s2>>s2;
        if(s.length()!=s2.length()){
            cout<<"NO TAUTOLOGIA\n";
            continue;
        }
        for(i=0;i<s.length();i++){
            if(s[i]==s2[i]){
                continue;
            }
            if(s[i]>'Z'){
                if(s2[i]+diff==s[i]){
                    continue;
                }
            }
            if(s[i]+diff==s2[i]){
                continue;
            }
            break;
        }
        if(i==s.length()){
            cout<<"TAUTOLOGIA\n";
        }
        else{
            cout<<"NO TAUTOLOGIA\n";
        }
    }
    return 0;
}

