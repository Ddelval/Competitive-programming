// AceptaElReto 141:  Paréntesis balanceados
//
//  main.cpp
//  141
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    stack<char> st;
    string s;
    bool exit;
    while(getline(cin,s)){
        exit=false;
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                    st.push(s[i]);
                    break;
                case ')':
                    if(!st.empty()&&st.top()=='('){st.pop();}
                    else{exit=true;}
                    break;
                case ']':
                    if(!st.empty()&&st.top()=='['){st.pop();}
                    else{exit=true;}
                    break;
                case '}':
                    if(!st.empty()&&st.top()=='{'){st.pop();}
                    else{exit=true;}
                    break;
            }
            if(exit){
                break;
            }
        }
        if(exit||!st.empty()){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}
