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
long c;
long gcd(long a,long b){
    c=a%b;
    if(c)return gcd(b,c);
    else return b;
}
long gcda(long a,long b){
    if(a>=b) return gcd(a,b);
    else return gcd(b,a);
}
int main() {
    ios::sync_with_stdio(false);
    int length;
    int num;
    int mult;
    while(cin>>length&&length){
        mult=1;
        for(int i=0;i<length;++i){
            cin>>num;
            mult/=gcd(num,mult);
            mult*=num;
        }
        cout<<mult<<"\n";
        
    }
    return 0;
}

