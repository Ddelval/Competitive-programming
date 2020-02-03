//
//  main.cpp
//  399
//
//  Created by David del Val on 09/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    long long int temp;
    int contador, i, ex;
    int cont2;
    while(1){
        vector<long long int> v,output;
        ex=0;
        cin>>temp;
        if(!temp){
            break;
        }
        v.push_back(temp);
        output.push_back(0);
        contador=0;
        while(1){
            cin>>temp;
            if(!temp){break;}
            v.push_back(temp);
            output.push_back(0);
            contador++;
        }
        sort(v.begin(), v.end());
        
        if(contador%2==0){
        if(contador==0){cout<<v[0]<<endl;continue;}
        if(v[contador]<=v[contador-1]){cout<<"NO\n";continue;}
        
        for(i=contador-1;i>=2;i-=2){
            if(v[i]!=v[i-1]||v[i]<=v[i-2]){cout<<"NO\n";ex=1;break;}
        }
        if(ex){continue;}
        }
        else{
            
            
            for(i=contador;i>=2;i-=2){
                if(v[i]!=v[i-1]||v[i]<=v[i-2]){cout<<"NO\n";ex=1;break;}
            }
            if(ex){continue;}
            
            
        }
        
        
        
        cont2=0;
        for(int i=0;i<=contador;i++){
            if((i%2)){
                //Odd
                output[cont2]=v[i];
                
                cont2++;
            }
            else{
                //Even
                output[contador-cont2]=v[i];
            }
        }
        for(int i=0;i<contador;i++){
            cout<<output[i]<<" ";
        }
        cout<<output[contador]<<endl;
        
        /*
        for(i=0;i<=contador/2;i++){
            cout<<v[2*i]<<" ";
        }
        for(i=(contador/2)+1;i>=2;i-=2){
            cout<<v[i]<<" ";
            if(i==2){cout<<v[0];}
        }
        cout<<endl;
*/
    }
    
    return 0;
}
