//
//  main.cpp
//  124
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string s,a;
    bool carry;
    char k,l;
    int carrycounter=0;
    cin>>s>>a;
    while(s!="0"||a!="0"){
        carrycounter=0;
        carry=false;
        if(s.length()==a.length()){
            for(int i=1;i<=s.length();i++){
                k=s[s.length()-i];
                l=a[a.length()-i];
                carry=(k+l-'0'-'0'+carry)>9;
                carrycounter+=carry;
            }
        }
        if(a.length()!=s.length()){
            for(int i=1;i<=s.length()&&i<=a.length();i++){
                k=s[s.length()-i];
                l=a[a.length()-i];
                carry=(k+l-'0'-'0'+carry)>9;
                carrycounter+=carry;
            }
            if(a.length()>s.length()){
                for(int i=0;i<a.length()-s.length()-1&&carry;i++){
                    if(((char)a[a.length()-s.length()-1-i])-'0'+carry>9){
                        carrycounter++;
                    }
                    else{
                        carry=false;
                    }
                }
                
            }
            else{
                for(int i=0;i<s.length()-a.length()-1&&carry;i++){
                    if(((char)s[s.length()-a.length()-1-i])-'0'+carry>9){
                        carrycounter++;
                    }
                    else{
                        carry=false;
                    }
                }
                
            }
            
        }
        cout<<carrycounter<<"\n";
        cin>>s>>a;
    }
    return 0;
}
