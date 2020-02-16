// AceptaElReto 177:  Juego con números
//
//  main.cpp
//  177
//
//  Created by David del Val on 01/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
bool cmp(int i,int j){return i>j;}
int getlength(long l){
    int length=1;;
    while(l>pow(10,length)){
        length++;
    }
    return length;
}
int main(int argc, const char * argv[]) {
    long a[8];
    priority_queue<long> pq;
    vector<long> vec;
    long currentgo;
    long maxtogo;
    int ic,ac;
    long el;
    string aux;
    int length;
    long saux;
    while(1){
        cin>>a[0];
        if(!a[0]){
            break;
        }
        cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7];
        
        for(int i=0;i<8;i++){
            maxtogo=a[i]+10000000;
            length=getlength(maxtogo);
            //aux=to_string(maxtogo);
            //length=(int)aux.length();
            currentgo=pow(10,length-1);
            
            while(currentgo>a[i]){
                pq.push(-1*(currentgo-a[i]));
                //vec.push_back(currentgo-a[i]);
                currentgo/=10;
            }
        }
        //sort(vec.begin(),vec.end(),cmp);
        ic=0;ac=0;saux=-1;
        /*while(!vec.empty()){
            if(saux==vec.back()){
                vec.pop_back();
                continue;
            }
            if(vec.back()%2){
                //Odd
                ic++;
                cout<<"Zipi: "<<vec.back()<<endl;
            }
            else{
                //Even
                ac++;
                cout<<"Zape: "<<vec.back()<<endl;
            }
            saux=vec.back();
            vec.pop_back();
        }*/
        while(!pq.empty()){
            el=-1*pq.top();
            if(saux==el){
                pq.pop();
                continue;
            }
            if(el%2){
                //Odd
                ic++;
                cout<<"Zipi: "<<el<<endl;
            }
            else{
                //Even
                ac++;
                cout<<"Zape: "<<el<<endl;
            }
            saux=el;
            pq.pop();
        }
        cout<<"Resultado final: Zipi: "<<ic<<" Zape: "<<ac<<endl;
        
    }
    
    return 0;
}
