//
//  main.cpp
//  1148-C
//
//  Created by David del Val on 01/06/2019.
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
#include <sstream>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int len;
int aux;
stringstream o;
vector<int> vi;
vector<int> pos;
//Swap elements in positions a and b
void sw (int a, int b){
    o<<a<<" "<<b<<"\n";
    int aux;
    aux=vi[a];
    vi[a]=vi[b];
    vi[b]=aux;
    aux=pos[vi[a]];
    pos[vi[a]]=pos[vi[b]];
    pos[vi[b]]=aux;
}

int main(){
    ios::sync_with_stdio(false);
    int swaps;
    while(cin>>len){
        o.str("");
        vi.clear();
        vi.reserve(len+1);
        pos.assign(len+1, 0);
        int val;
        vi.push_back(0);
        for(int i=1;i<=len;++i){
            cin>>val;
            vi.push_back(val);
            pos[val]=i;
        }
        swaps=0;
        for(int i=len/2+1;i<=len;++i){
            //We are going to position the element in the i-th position
            if(vi[i]==i){
                continue;
            }
            else if(pos[i]<len/2+1){
                int a=pos[i];
                if(a!=len)sw(a,len);
                sw(1,len);
                sw(1,i);
                sw(len,1);
                if(a!=len)sw(a,len);
                if(a!=len)swaps+=5;
                else swaps+=3;
            }
            else{
                //The element is in right side
                //Swap with the first and then swap again
                int a=pos[i];
                if(a!=1)sw(1,a);
                sw(1,i);
                if(a!=1)sw(1,a);
                if(a!=1)swaps+=3;
                else swaps+=1;
            }
        }
        //Fix the left part
        for(int i=1;i<=len/2;++i){
            if(vi[i]==i)continue;
            int a=pos[i];
            if(a!=len)sw(a,len);
            sw(i,len);
            if(a!=len)sw(a,len);
            if(a!=len)swaps+=3;
            else swaps+=1;
        }
        cout<<swaps<<"\n";
        cout<<o.str();
        
        
    }
    
    return 0;
}
