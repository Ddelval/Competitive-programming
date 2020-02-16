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
bool board[1000][1000];
string s;
deque<char> d;
int main() {
    ios::sync_with_stdio(false);
    while(getline(cin,s)){
        //Create the board
        for(int i=0;i<s.length();++i){
            for(int j=0;j<s.length();++j){
                if(s[i]==s[j]) board[i][j]=true;
                else board[i][j]=false;
            }
        }
        //Find the longest diagonal
        int max=0,a;
        int cpos=-1;
        int counter;
        for(int spos=(int)s.length()/2;spos<s.length()-1;++spos){
            counter=0;a=1;
            for(int i=spos;i<s.length()-1;++i){
                if(i+a>s.length()||i-a>s.length()) break;
                if(board[i+a][i-a]&&board[i-a][i+a]) counter++;
                else a++; i--;
            }
            if(counter>=max){
                max=counter;
                cpos=spos;
            }
        }
        for(int spos=1;spos<s.length()/2;++spos){
            counter=0;a=1;
            for(int i=spos;i<s.length()-1;++i){
                if(i+a>s.length()||i-a>s.length()) break;
                if(board[i+a][i-a]&&board[i-a][i+a]) counter++;
                else a++; i--;
            }
            if(counter>max){
                max=counter;
                cpos=spos;
            }
        }
        //Find the palindrome from the central position
        d.push_back(s[cpos]);
        int rcursor=cpos;
        int lcursor=cpos;
        if(s[rcursor-1]==s[cpos]){
            d.push_back(s[rcursor-1]);
        }
        if(s[lcursor-1]==s[cpos]){
            d.push_front(s[lcursor-1]);
        }
        int goleft,goright;
        while(lcursor>=0&&rcursor<s.length()){
            if(s[rcursor-1]==s[lcursor+1]) {d.push_back(s[rcursor-1]);d.push_front(s[rcursor-1]); continue;}
            
        }
    }
    return 0;
}

