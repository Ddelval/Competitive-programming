//
//  main.cpp
//  First
//
//  Created by David del Val on 19/06/2019.
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
#include <string.h>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    int a,b,c;
    int dist;
    cin>>a>>b>>c>>dist;
    int l=min(a,b);
    l=min(l,c);
    int r=max(a,b);
    r=max(r,c);
    int movements=0;
    int cent;
    if(a!=r&&a!=l)cent=a;
    else if (b!=r&&b!=l) cent=b;
    else cent=c;
    /*if(r-l<2*dist){
        movements+=2*dist-(r-l);
    }
    int tospare=movements;
    tospare-=dist-(r-cent);
    tospare-=dist
    if(r-cent<dist||cent-l<dist){
        movements+=min(dist+cent-r,dist+l-cent);
    }*/
    int a1,a2;
    a1=r-cent;
    if(a1>dist)a1=dist;
    a2=cent-l;
    if(a2>dist) a2=dist;
    movements=dist-(a1)+dist-(a2);
    if(movements <0)movements=0;
    cout<<movements;
    return 0;
}
