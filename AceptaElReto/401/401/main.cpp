#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    string s1,s2;
    int coinc;
    bool flag;
    bool same;
    for(int i=0;i<cas;i++){
        cin>>s1>>s2;
        coinc=0;
        if(s1.length()!=s2.length()){
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<s1.length();i++){
            if(s1[i]>='a'&&s1[i]<='z'){
                s1[i]=s1[i]-'a'+'A';
            }
            if(s2[i]>='a'&&s2[i]<='z'){
                s2[i]=s2[i]-'a'+'A';
            }
            
        }
        replace(s1.begin(),s1.end(),'B','V');
        replace(s2.begin(),s2.end(),'B','V');
        if(s1==s2){
            cout<<"NO\n";
            continue;
        }
        same=false;
        s1.append(s1);
        int lim=(int)s1.length()-(int)s2.length();
        for(int i=0;i<lim;i++){
            if(s1[i]==s2[0]){
                flag=true;
                for(int j=0;j<s2.length();j++){
                    if(s1[i+j]!=s2[j]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    same=true;
                    break;
                }
            }
        }
        
        if(same){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}

