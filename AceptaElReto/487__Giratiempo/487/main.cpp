#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    long long int  cas;
    long long int  n;
    long long int  suma;
    long long int veces;
    cin>>cas;
    for(int i=0;i<cas;i++){
        cin>>n;
        suma=n;
        while(n>=3600){
            veces=n/3600;
            suma+=veces;
            n=n-veces*3600+veces;
        }
        cout<<suma<<"\n";
        
    }
    return 0;
}
