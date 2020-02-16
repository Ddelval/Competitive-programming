// AceptaElReto 317:  El código de la T.I.A.
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
#define mp(x,y) make_pair(x,y)
using namespace std;
set<string> symb;
map<string,int> DP;
int max_length;
long counter;
long mod(long a){
    if(a<0) a+=1000000007;
    return a;
}
void count(string s){
    long a;
    string s1,s2;
    if(!s.length()) {counter++; counter%=1000000007; return;}
    if(DP.count(s)){
        counter+=DP[s];
        counter%=1000000007;
        return;
    }
    while(s[0]=='0'){
        s=s.substr(1);
    }
    for(int i=1;i<=min((int)s.length(),max_length)&&s[i-1]!='0';++i){
        s1=s.substr(0,i);
        if(symb.count(s1)){
            a=counter;
            s2=s.substr(i);
            count(s2);
            DP.insert(mp(s2,mod(counter-a)));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int simbols;
    int code;
    string input;
    while(cin>>simbols&&simbols){
        DP.clear();
        symb.clear();
        counter=0;
        max_length=1;
        for(int i=0;i<simbols;++i){
            cin>>code;
            symb.insert(to_string(code));
            while(code>pow(10,max_length)){
                max_length++;
            }
            
        }
        cin>>input;
        count(input);
        cout<<counter<<"\n";
        
        
    }
    return 0;
}

