//
//  main.cpp
//  100
//
//  Created by David del Val on 28/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
bool order2(int i,int j){
    return i>j;
}
int main(int argc, const char * argv[]) {
    int N;
    int num1,num2;
    int a1,a2,a3,a4;
    int counter;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num1;
        if(num1==6174){
            cout<<0<<endl;
            continue;
        }
        a1=num1%10;
        a2=(num1%100)/10;
        a3=(num1%1000)/100;
        a4=(num1%10000)/1000;
        if(a1==a2&&a2==a3&&a3==a4){
            cout<<8<<endl;
        }
        else{
            vi v;
            counter=0;
            while(1){
                v.clear();
                v.push_back(a1);
                v.push_back(a2);
                v.push_back(a3);
                v.push_back(a4);
                sort(v.begin(),v.end(),order2);
                num2=v[3]*1000+v[2]*100+v[1]*10+v[0];
                num1=v[0]*1000+v[1]*100+v[2]*10+v[3];
                num1=num1-num2;
                counter++;
                if(num1==6174){
                    break;
                }
                a1=num1%10;
                a2=(num1%100)/10;
                a3=(num1%1000)/100;
                a4=(num1%10000)/1000;
            }
            cout<<counter<<endl;
        }
        
    }
    
    
    return 0;
}
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    string s1,s2;
    int r,n;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s1;
        for(n=0;s1!="6174";n++){
            while(s1.length() != 4)
                s1.insert(0, "0");
            
            s2=s1;
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end(),greater<char>());
            r= stoi(s2)-stoi(s1);
            if(r==0){
                n=8;
                break;
            }
            s1=to_string(r);
        }
        cout<<n<<endl;
    }
    return 0;
}
