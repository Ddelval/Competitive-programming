// AceptaElReto 478:  Conjuritis
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long int ll;
int hech[200000];
bool fon[500001];
int main() {
    ios::sync_with_stdio(false);
    int leng;
    int pleng=0;
    ll damage;
    ll suma;
    ll n1,n2;
    ll targetnumber;
    while(cin>>leng&&leng){
        if(pleng){
            for(int i=0;i<pleng;i++){
                fon[hech[i]]=false;
            }
        }
        pleng=leng;
        suma=0;
        n1=n2=0;
        for(int i=0;i<leng;i++){
            cin>>hech[i];
            fon[hech[i]]=true;
            suma+=hech[i];
        }
        cin>>damage;
        targetnumber=suma-damage;
        for(int i=0;i<leng;i++){
            if(fon[targetnumber-hech[i]]){
                n1=hech[i];
                n2=targetnumber-n1;
                break;
            }
        }
        if(n1>n2){
            swap(n1,n2);
        }
        cout<<n1<<" "<<n2<<"\n";
    }
        
    
    return 0;
}

