// AceptaElReto 162:  Tableros de Ajedrez
//
//  main.cpp
//  162
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    char c;
    string s;
    while(cin>>size&&size){
        cin>>c;
        string a(1,c);
        s="";
        s.append("|");
        for(int i=0;i<8*size;i++){
            s.append("-");
        }
        s.append("|\n");
        for(int i=0;i<4;i++){
            for(int j=0;j<size;j++){
                s.append("|");
                for(int i=0;i<4;i++){
                    for(int i=0;i<size;i++){
                        s.append(" ");
                    }
                    for(int i=0;i<size;i++){
                        s.append(a);
                    }
                    
                }
                s.append("|\n");
            }
            for(int j=0;j<size;j++){
                s.append("|");
                for(int i=0;i<4;i++){
                    for(int i=0;i<size;i++){
                        s.append(a);
                    }
                    for(int i=0;i<size;i++){
                        s.append(" ");
                    }
                }
                s.append("|\n");
            }
        }
        s.append("|");
        for(int i=0;i<8*size;i++){
            s.append("-");
        }
        s.append("|\n");
        cout<<s;
    }
    return 0;
}
