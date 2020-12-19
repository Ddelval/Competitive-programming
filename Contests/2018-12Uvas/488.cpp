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
    cin.tie(NULL);
    int c;
    int s;
    int counter;
    int pts, zz;
    int aux,paux;
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>pts>>zz;
        counter=0;
        cin>>paux;
        s=paux;
        for(int i=1;i<pts;i++){
            cin>>aux;
            s+=aux-paux;
            if(s>zz){
                counter++;
                s=aux-paux;
            }
            paux=aux;
        }
        counter++;
        cout<<counter<<"\n";
    }
    return 0;
}

