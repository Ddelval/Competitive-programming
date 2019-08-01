//
//  main.cpp
//  1174-A
//
//  Created by David del Val on 08/06/2019.
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
int data[2005];
int n;
ll suma1,suma2;
int  max1,min1,max2,min2;
int maxpos1,minpos1,maxpos2,minpos2;
void outarray(){
    cout<<data[0];
    for(int i=1;i<2*n;++i){
        cout<<" "<<data[i];
    }
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        suma1=suma2=0;
        max1=max2=0;
        min1=min2=9*10e6;
        for(int i=0;i<n;++i){
            cin>>data[i];
            suma1+=data[i];
            if(data[i]>max1){ max1=data[i]; maxpos1=i;}
            if(data[i]<min1){ min1=data[i]; minpos1=i;}
        }
        for(int i=n;i<2*n;++i){
            cin>>data[i];
            suma2+=data[i];
            if(data[i]>max2){ max2=data[i]; maxpos2=i;}
            if(data[i]<min2){ min2=data[i]; minpos2=i;}
        }
        if(suma1!=suma2){
            outarray();
            continue;
        }
        if(max1==min1&&min2==max2&&max1==min2){
            cout<<"-1\n";
            continue;
        }
        if(max1!=max2){
            swap(data[maxpos1], data[maxpos2]);
            outarray();
        }
        else if(min1!=min2){
            swap(data[minpos1], data[minpos2]);
            outarray();
        }
        else if(max1!=min2){
            swap(data[maxpos1], data[minpos2]);
            outarray();
        }
        else if(min1!=max2){
            swap(data[minpos1], data[maxpos2]);
            outarray();
        }
        
    }
    
    return 0;
}
