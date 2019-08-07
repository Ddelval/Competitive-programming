// AceptaElReto 105:  Ventas
//
//  main.cpp
//  105
//
//  Created by David del Val on 02/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
    int weeknumber;
    double amount;
}day;
typedef vector<day> vec;
bool mybool(day d,day d2){return d.amount>d2.amount;}
int main(int argc, const char * argv[]) {
    double weekaverage;
    day max,min;
    int maxamount,minamount;
    int domsell;
    while(true){
        vec v;
        weekaverage=0;
        day d;
        d.weeknumber=1;
        
        cin>>d.amount;
        if(d.amount==-1){
            break;
        }
        weekaverage+=d.amount;
        v.push_back(d);
        d.weeknumber=2;
        cin>>d.amount;
        weekaverage+=d.amount;
        v.push_back(d);
        d.weeknumber=3;
        cin>>d.amount;
        weekaverage+=d.amount;
        v.push_back(d);
        d.weeknumber=4;
        cin>>d.amount;
        weekaverage+=d.amount;
        v.push_back(d);
        d.weeknumber=5;
        cin>>d.amount;
        v.push_back(d);
        weekaverage+=d.amount;
        d.weeknumber=6;
        cin>>d.amount;
        weekaverage+=d.amount;
        v.push_back(d);
        weekaverage/=6;
        domsell=d.amount;
        sort(v.begin(),v.end(),mybool);
        max = v.front();
        maxamount=max.weeknumber;
        min=v.back();
        minamount=min.weeknumber;
        if(maxamount==minamount){
            cout<<"EMPATE ";
        }else{
            switch(maxamount){
                case 1: cout<<"MARTES"; break;
                case 2: cout<<"MIERCOLES"; break;
                case 3: cout<<"JUEVES"; break;
                case 4: cout<<"VIERNES"; break;
                case 5: cout<<"SABADO"; break;
                case 6: cout<<"DOMINGO"; break;
                    
            }
            cout<<" ";
            switch(minamount){
                case 1: cout<<"MARTES"; break;
                case 2: cout<<"MIERCOLES"; break;
                case 3: cout<<"JUEVES"; break;
                case 4: cout<<"VIERNES"; break;
                case 5: cout<<"SABADO"; break;
                case 6: cout<<"DOMINGO"; break;
                    
            }
            cout<<" ";
        }
       
        if(domsell>weekaverage){
            cout<<"SI"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
