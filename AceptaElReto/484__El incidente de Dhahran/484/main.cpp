// AceptaElReto 484:  El incidente de Dhahran
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    
    while(getline(cin,s)){
        string a;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                s[i]='&';
            }
            else{
                break;
            }
        }
        if(find(s.begin(),s.end(),'.')!=s.end()){
            for(int i=(int)s.length()-1;i>=0;i--){
                if(s[i]=='0'){
                    s[i]='&';
                }
                else{
                    break;
                }
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='&'){
                
            }
            else{
                a.push_back(s[i]);
            }
        }
        if(a=="."){
            cout<<"0";
        }
        else if(a==""){
            cout<<"0";
        }
        else{
            if(a[a.length()-1]=='.'){
                for(int i=0;i<a.length()-1;i++){
                    cout<<a[i];
                }
            }
            else{
                if(a[0]=='.'){
                    cout<<"0";
                }
                cout<<a;
            }
        }
        
        cout<<"\n";
    }
    return 0;
}

