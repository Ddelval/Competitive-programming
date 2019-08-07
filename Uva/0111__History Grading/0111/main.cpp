// UVa Online Judge 111: History_Grading
//
//  main.cpp
//  0111
//
//  Created by David del Val on 28/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int maximum_chain=0;

void checksubset(int data[20],int length,int current_chain){
    int select= data[0];
    /*cout<<"Sel:"<<select<<"-->";
    for(int y=0;y<length;y++){
        cout<<data[y]<<" ";
    }
    cout<<endl<<current_chain<<","<<length<<endl;*/
    
    //eliminate all the elements that are less than the selected one;
    /*if(length==1){
        if(current_chain>maximum_chain){
            maximum_chain=current_chain+2;
            cout<<"ASSIGNED:"<<maximum_chain<<endl;
        }
    }*/
    /*else*/ if(length>0){
        if(current_chain>=maximum_chain){
            maximum_chain=current_chain+1;
            //cout<<"ASSIGNED:"<<maximum_chain<<endl;
        }
    }
    int newlen=0;
    for(int i=1;i<length;i++){
        if(data[i]>select){
            data[newlen]=data[i];
            newlen++;
        }
    }
    for(int i=0;i<newlen;i++){
        int newdata[20];
        int newlength=0;
        for(int j=i;j<newlen;j++){
            if(data[j]!=-1){
                newdata[newlength]=data[j];
                newlength++;
            }
            
        }
       /*cout<<"End of cyclce:";
        for(int y=0;y<newlength;y++){
            cout<<newdata[y]<<" ";
        }
        cout<<endl;*/
        checksubset(newdata, newlength, current_chain+1);
        
    }
}



int main(int argc, const char * argv[]) {
    int equivalence [20];
    char equivalencec [41];
    int equivalence2 [20];
    int data[20];
    int feed[20];
    int tmp=0;
    int length;
    char temp[3];
    char datac[41];
    int tempcount=0;
    int nextlength=-1;
    bool goagain= true;
    
    cin>>length;
    cin.getline(equivalencec, 41);
    while(goagain){
        tmp=0;
        tempcount=0;
        goagain=false;
        if(nextlength!=-1){
            length=nextlength;
        }
        cin.getline(equivalencec, 41);
        int j=0;
        for(int i=0;i<=length*2;i++){
            if(equivalencec[i]!=' '&&equivalencec[i]!='\0'){
                temp[tempcount]=equivalencec[i];
                tempcount++;
            }
            else{
                //convert and store
                if(tempcount==1){
                    tmp=temp[0]-1-'0';
                }
                else if(tempcount==2){
                    tmp=(temp[1]-'0'+10*(temp[0]-'0'))-1;
                }
                equivalence[j]=tmp;
                j++;
                tempcount=0;
            }
        }
        for(int i=0;i<length;i++){
            equivalence2[equivalence[i]]=i;
        }
        while(cin.getline(datac, 41)){
            if(strlen(datac)<=2&&strlen(datac)!=0){
                if(strlen(datac)==1){
                    nextlength=datac[0]-'0';
                }
                else{
                    nextlength=datac[1]-'0'+10*(datac[0]-'0');
                    
                }
                
                goagain=true;
                break;
            }
            else{
                j=0;
                tempcount=0;
                for(int i=0;datac[i-1]!='\0'||!i;i++){
                    if(datac[i]!=' '&&datac[i]!='\0'){
                        temp[tempcount]=datac[i];
                        tempcount++;
                    }
                    else{
                        //convert and store
                        if(tempcount==1){
                            tmp=temp[0]-1-'0';
                        }
                        else if(tempcount==2){
                            tmp=(temp[1]-'0'+10*(temp[0]-'0'))-1;
                        }
                        data[tmp]=equivalence[j];
                        j++;
                        tempcount=0;
                    }
                    
                }
                cout<<endl;
                    for(int j=0;j<length;j++){
                        cout<<data[j]<<", ";
                    }
                    cout<<endl;
                
                    for(int j=0;j<length;j++){
                        for(int k=0;k<length-j;k++){
                            feed[k]=data[k+j];
                            
                        }
                        /*for(int y=0;y<length-j;y++){
                         cout<<feed[y]<<" ";
                         }
                         cout<<endl;*/
                        checksubset(feed, length-j, 0);

                    }
                    cout<<maximum_chain<<endl;
                    maximum_chain=0;
            }
        }
        /*cout<<endl;
        for(int j=0;j<length;j++){
            cout<<equivalence[j]<<", ";
        }
        cout<<endl;
        cout<<endl;
        for(int i=0;i<w;i++){
            for(int j=0;j<length;j++){
                cout<<data[i][j]<<", ";
            }
            cout<<endl;
        }
        */
        
        
        
        
        
        
        
        
        
    }
    
    return 0;
}
