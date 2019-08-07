// AceptaElReto 152:  Va de modas...
//
//  main.cpp
//  152
//
//  Created by David del Val on 26/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int> data;
    int entries;
    int aux;
    int max;
    int maxvalue;
    while(cin>>entries&&entries){
        data.clear();
        max=0;
        maxvalue=0;
        for(int i=0;i<entries;i++){
            cin>>aux;
            if(data.find(aux)!=data.end()){
                data[aux]++;
                if(data[aux]>maxvalue){
                    maxvalue=data[aux];
                    max=aux;
                }
            }
            else{
                data.insert(make_pair(aux,1));
                if(maxvalue==0){
                    max=aux;
                    maxvalue=1;
                }
            }
        }
        cout<<max<<"\n";
        
        
    }
    return 0;
}
