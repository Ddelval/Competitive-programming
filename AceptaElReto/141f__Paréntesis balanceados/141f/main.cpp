//
//  main.cpp
//  141
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    stack<char> st;
    char c=' ';
    bool exit=false;
    while(1){
        while(!st.empty()){
            st.pop();
        }
        exit=false;
        c=' ';
        while(c!='\n'){
            c=getchar();
            switch(c){
                case '(':
                case '[':
                case '{':
                    st.push(c);
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
            if(c==EOF){
                break;
            }
        }
        if(c==EOF){
            break;
        }
        if(exit||!st.empty()){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
