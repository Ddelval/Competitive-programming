//
//  main.cpp
//  1169-A
//
//  Created by David del Val on 09/06/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int n,a,x,b,y;
int mod(int x){
    while(x<=0) x+=n;
    return (x%n==0)? n:x%n;
}
int main(){
    ios::sync_with_stdio(false);

    while(cin>>n>>a>>x>>b>>y){
        if(a==b){
            cout<<"YES";
            continue;
        }
        if(a==x||b==y){
            cout<<"NO";
            continue;
        }
        if(a<b){
            if((b-a)%2==0){
                //They can meet
                int meet =a+(b-a)/2;
                if((y>b || meet>=y)&&(x<a||meet<=x)){
                    cout<<"YES";
                    continue;
                }
            }
            if((x<a||b<=x)&&(y>b||a>=y)){
                //They can get to each other position
                swap(a, b);
            }
            else{
                cout<<"NO"; continue;
            }
        }
        if(a==x||b==y){
            cout<<"NO";
            continue;
        }
        //Now we have that a>b
        if(mod(b-a)%2==0){
            //They can meet
            int meet=mod(a+mod(b-a)/2);
            if((y>b&&(meet<=b||meet>=y))||(y<b&&(meet<=b&&meet>=y))){
                if((x<a&&(meet>=a||meet<=x))||(x>a&&(meet>=a&&meet<=x))){
                    cout<<"YES"; continue;
                }
            }
        }
        if(y<x){
            if((x<a)&&(y>b)){
                //They can get to each other position
                swap(a, b);
                if((b-a)%2==0){
                    //They can meet
                    int meet =a+(b-a)/2;
                    if((y>b || meet>=y)&&(x<a||meet<=x)){
                        cout<<"YES";
                        continue;
                    }
                }
                if((x<a||b<=x)&&(y>b||a>=y)){
                    //They can get to each other position
                    swap(a, b);
                }
                else{
                    cout<<"NO"; continue;
                }
            }
            
            
        }
        cout<<"NO";
        
        
    }
    
    return 0;
}
