#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cn;
    int cg;
    char c;
    bool out;
    while(1){
        out =true;
        cn=0;
        cg=0;
        while(cin>>c){
            if(c=='.'){
                break;
            }
            out=false;
            
                if(c=='N'){
                    cn++;
                }
                if(c=='G'){
                    cg++;
                }
        }
        if(out){
            break;
        }
        if(cg%2){
            //Sobra un gris
            if(cn%2){
                cout<<"PAREJA MIXTA\n";
            }
            else{
                cout<<"GRIS SOLITARIO\n";
            }
        }
        else{
            if(cn%2){
                cout<<"NEGRO SOLITARIO\n";
            }
            else{
                cout<<"EMPAREJADOS\n";
            }
        }
        
        
    }
    return 0;
}

