// AceptaElReto 324:  El teorema del punto fijo
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int c;
int gcd(int a,int b){
    c=a%b;
    if(c)return gcd(b,c);
    else return b;
}
int gcda(int a,int b){
    if(a>=b)return gcd(a,b);
    else return gcd(b,a);
}
int mov[110];
int patt[110];
int main() {
    ios::sync_with_stdio(false);
    int length;
    int counter, fin;
    bool b;
    while(cin>>length&&length){
        b=true;
        for(int i=1;i<=length;++i){
            cin>>mov[i];
            patt[i]=mov[i];
            if(b&&mov[i]!=i) b=false;
        }
        if(b){
            cout<<"1\n";
            continue;
        }
        fin=1;
        for(int i=1;i<=length;++i){
            counter=1;
            while(mov[i]!=i){
                mov[i]=patt[mov[i]];
                counter++;
            }
            fin/=gcda(fin,counter);
            fin*=counter;
        }
        cout<<fin<<"\n";
    }
   
    return 0;
}

