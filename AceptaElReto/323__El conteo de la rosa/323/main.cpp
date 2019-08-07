// AceptaElReto 323:  El conteo de la rosa
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
int beg,en;
//Sum from 1 to i
int sum(int i){
    if(i==0) return 0;
    int digits=log10(i)+1;
    switch(digits){
        case 1: return i;
        case 2: return 2*(i-9)+9;
        case 3: return 3*(i-99)+189;
        case 4: return 4*(i-999)+2889;
        case 5: return 5*(i-9999)+38889;
        case 6: return 6*(i-99999)+488889;
        case 7: return 5888896;
    }
    return 0;
}
//Calculate the number that has that sum of digits
int calculate(int i){
    if(i<10) return i;
    if(i<190) return 9+(i-9)/2;
    if(i<2890) return 99+(i-189)/3;
    if(i<38890) return 999+(i-2889)/4;
    if(i<488890) return 9999+(i-38889)/5;
    if(i<5888897) return 99999+(i-488889)/6;
    return 1000000;
}
int main() {
    ios::sync_with_stdio(false);
    int dig;
    int d1,d2;
    int target;
    while(cin>>beg>>en&&beg){
        d1=sum(en);
        d2=sum(beg-1);
        dig=d1-d2;
        target=dig/2+d2; //We have to add the sum from 1 to the starting point without counting it
        cout<<calculate(target)<<"\n";
    }
    
    
    return 0;
}

