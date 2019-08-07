//
//  main.cpp
//  102
//
//  Created by David del Val on 29/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    string in;
    int code;
    string word;
    char res;
    int counter;
    while(true){
        getline(cin,in);
        word=in.substr(1);
        code= -in[0]+'p';
        if(code<0){
            code=26-(-1)*code;
        }
        for(int i=0;i<word.length();i++){
            res=word[i];
            if(res>='a'&&res<='z'){
                //Lowercase
                res=res+code;
                while(res<'a'){
                    res+=('z'-'a'+1);
                }
                
                    while(res>'z'){
                        res-=('z'-'a'+1);
                    }
                
            }
            else if(res>='A'&&res<='Z'){
                //Uppercase
                res=res+code;
                while(res<'A'){
                    res+=('Z'-'A'+1);
                }
                
                    while(res>'Z'){
                        res-=('Z'-'A'+1);
                    }
                
            }
            word[i]=res;
        }
        if(word!="FIN"){
            counter=0;
            for(int j=0;j<word.length();j++){
                switch(word[j]){
                    case 'a':case'e':case'i':case'u':case'o':
                    case 'A':case'E':case'I':case'U':case'O':
                        counter++;
                        break;
                        
                }
            }
            cout<<counter<<endl;
        }
        else{
            break;
        }
    }
    return 0;
}
/*
 
 #include <iostream>
 #include <string>
 using namespace std;
 int main() {
 int code;
 string word;
 string alphabet ="abcdefghijklmnopqrstuvwxyz";
 string Alphabet ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 char res;
 int rescode;
 int counter;
 while(true){
 getline(cin,word);
 code=-alphabet.find(word[0])+alphabet.find('p');
 word=word.substr(1);
 if(code<0){
 code=alphabet.length()+code;
 }
 for(int i=0;i<word.length();i++){
 res=word[i];
 if(res>='a'&&res<='z'){
 //Lowercase
 rescode=(alphabet.find(res)+code)%alphabet.length();
 while(rescode<0){
 rescode+=alphabet.length();
 }
 res=alphabet[rescode];
 
 }
 else if(res>='A'&&res<='Z'){
 //Uppercase
 rescode=(Alphabet.find(res)+code)%Alphabet.length();
 while(rescode<0){
 rescode+=Alphabet.length();
 }
 res=Alphabet[rescode];
 
 }
 word[i]=res;
 }
 if(word!="FIN"){
 counter=0;
 for(int j=0;j<word.length();j++){
 switch(word[j]){
 case 'a':case'e':case'i':case'u':case'o':
 case 'A':case'E':case'I':case'U':case'O':
 counter++;
 break;
 
 }
 }
 cout<<counter<<endl;
 }
 else{
 break;
 }
 }
 return 0;
 }

 
 
 */
