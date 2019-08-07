// AceptaElReto 403:  En campos de fútbol
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    int sur,numb;
    int lb,ub;
    cin>>n;
    lb=90*45;
    ub=120*90;
    for(int i=0;i<n;i++){
        cin>>sur>>numb;
        if(numb*lb<=sur&&numb*ub>=sur){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}

