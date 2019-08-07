// AceptaElReto 470:  Montando semáforos
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <stack>
#include <queue>
using namespace std;
string s;

int main() {
    ios::sync_with_stdio(false);
    char x;
    int y;
    while(getline(cin,s)){
        if (s == "") {
            return 0;
        }
        stack<char> mem;
        y=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'||s[i]=='A'){
                mem.push(s[i]);
                continue;
            }
            if(mem.size()<2){
                mem=stack<char>();
                continue;
            }
            x=mem.top();
            mem.pop();
            if(x=='A'&&mem.top()=='R'){
                mem.pop();
                y++;
            }
            else{
                mem=stack<char>();
            }
        }
        cout<<y<<"\n";
    }
    return 0;
}

