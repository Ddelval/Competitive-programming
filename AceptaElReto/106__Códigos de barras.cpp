// AceptaElReto 106:  Códigos de barras
//
//  main.cpp
//  106
//
//  Created by David del Val on 02/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string code;
    string defcode;
    int length;
    int add;
    int cont;
    int index;
    int addition;
    int tmp;
    int checknum;
    while(true){
        cin>>code;
        cont=0;
        index=0;
        addition=0;
        if(code[0]=='0'&&code[1]=='\0'){
            break;
        }
        length=code.length();
        if(length<=8){
            //EAN-8
            for(int i=length-2;i>=0;i-=2){
                addition+= (code[i]-'0')*3;
            }
            for(int i=length-3;i>=0;i-=2){
                addition+= (code[i]-'0');
            }
            tmp=addition%10;
            if(tmp){
                checknum=10-(addition%10);
            }else{
                checknum=0;
            }
            
            if(checknum==(defcode[length-1]-'0')){
                cout<<"SI";
            }
            else{
                cout<<"NO";
            }
        }
        else if(length<13){
            //EAN-13
            add= 13-length;
            for(cont=0;cont<add;cont++){
                defcode[cont]='0';
            }
            while(cont<13){
                defcode[cont]= code[index];
                index++;
                cont++;
            }
            for(int i=11;i>=0;i-=2){
                addition+= (defcode[i]-'0')*3;
            }
            for(int i=10;i>=0;i-=2){
                addition+= (defcode[i]-'0');
            }
            tmp=addition%10;
            if(tmp){
                checknum=10-(addition%10);
            }else{
                checknum=0;
            }
            if(checknum==(defcode[12]-'0')){
                cout<<"SI";
                if(defcode[0]=='0'){
                   cout<<" EEUU";
                }
                else if(defcode[0]=='5'&&defcode[1]=='0'){
                    cout<<" Inglaterra";
                }
                else if(defcode[0]=='7'&&defcode[1]=='0'){
                    cout<<" Noruega";
                }
                else if(defcode[0]=='3'&&defcode[1]=='8'&&defcode[2]=='0'){
                    cout<<" Bulgaria";
                }
                else if(defcode[0]=='5'&&defcode[1]=='3'&&defcode[2]=='9'){
                    cout<<" Irlanda";
                }
                else if(defcode[0]=='5'&&defcode[1]=='6'&&defcode[2]=='0'){
                    cout<<" Portugal";
                }
                else if(defcode[0]=='7'&&defcode[1]=='5'&&defcode[2]=='9'){
                    cout<<" Venezuela";
                }
                else if(defcode[0]=='8'&&defcode[1]=='5'&&defcode[2]=='0'){
                    cout<<" Cuba";
                }
                else if(defcode[0]=='8'&&defcode[1]=='9'&&defcode[2]=='0'){
                    cout<<" India";
                }
                else{
                    cout<<" Desconocido";
                }
            }
            else{
                cout<<"NO";
            }
        }
        else if(length==13){
            //EAN-13
            for(int i=11;i>=0;i-=2){
                addition+= (defcode[i]-'0')*3;
            }
            for(int i=10;i>=0;i-=2){
                addition+= (defcode[i]-'0');
            }
            tmp=addition%10;
            if(tmp){
                checknum=10-(addition%10);
            }else{
                checknum=0;
            }
            if(checknum==(defcode[12]-'0')){
                cout<<"SI";
                if(defcode[0]=='0'){
                    cout<<" EEUU";
                }
                else if(defcode[0]=='5'&&defcode[1]=='0'){
                    cout<<" Inglaterra";
                }
                else if(defcode[0]=='7'&&defcode[1]=='0'){
                    cout<<" Noruega";
                }
                else if(defcode[0]=='3'&&defcode[1]=='8'&&defcode[2]=='0'){
                    cout<<" Bulgaria";
                }
                else if(defcode[0]=='5'&&defcode[1]=='3'&&defcode[2]=='9'){
                    cout<<" Irlanda";
                }
                else if(defcode[0]=='5'&&defcode[1]=='6'&&defcode[2]=='0'){
                    cout<<" Portugal";
                }
                else if(defcode[0]=='7'&&defcode[1]=='5'&&defcode[2]=='9'){
                    cout<<" Venezuela";
                }
                else if(defcode[0]=='8'&&defcode[1]=='5'&&defcode[2]=='0'){
                    cout<<" Cuba";
                }
                else if(defcode[0]=='8'&&defcode[1]=='9'&&defcode[2]=='0'){
                    cout<<" India";
                }
                else{
                    cout<<" Desconocido";
                }
            }
            else{
                cout<<"NO";
            }
        }
        cout<<endl;
    }
    return 0;
}
