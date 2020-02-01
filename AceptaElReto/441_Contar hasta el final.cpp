//#include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;

string s2;
void add1(int pos){
    if(pos<0){
        string s3="1";
        s3.append(s2);
        s2=s3;
        return;
    }
    s2[pos]=(s2[pos]-'0'+1)%10+'0';
    if(s2[pos]=='0')add1(pos-1);
}

int main(){
    string s;
    while(cin>>s){
        s2="";
        for(auto a:s){
            if(a!='.')s2+=a;
        }
        add1(s2.length()-1);
        string s3="";
        for(int i=0;i<s2.length();++i){
            s3+=s2[i];
            if((s2.length()-1-i)%3==0&&i!=s2.length()-1){
                s3+=".";
            }
        }
        cout<<s3<<"\n";

    }

}