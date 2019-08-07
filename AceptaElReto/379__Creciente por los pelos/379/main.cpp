//
//  main.cpp
//  261
//
//  Created by David del Val on 28/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef stack<int> vi;
typedef queue<int> vc;
int main(int argc, const char * argv[]) {
    int size;
    int tmp;
    int a;
    scanf("%d",&size);
    stack<int> v;
    queue<int> va;
    while(size!=0){
        while(!v.empty()){
            v.pop();
        }
        while(!va.empty()){
            va.pop();
        }
        for(int i=0;i<size;i++){
            scanf("%d",&tmp);
            v.push(tmp);
            va.push(tmp);
        }
        int j=0;
        int i=0;
        for(i=0;i<size-1;i++){
            a=v.top();
            v.pop();
            if(a==v.top()){
                break;
            }
            
        }
        j=size-1-i;
        for(int i=0;i<j;i++){
            printf("%d ",va.front());
            va.pop();
        }
        for(i=j;i<size-1;i++){
            printf("%d ",va.front()+1);
        }
        if(i==size-1){
           printf("%d\n",va.front()+1);
        }
        else{
            printf("\n");
        }
        scanf("%d",&size);
        
        
    }
    
    return 0;
}
