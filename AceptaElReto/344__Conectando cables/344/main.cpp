// AceptaElReto 344:  Conectando cables
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
#define mp(x,y) make_pair(x,y)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int cas;
    int length;
    string s;
    int c1,c2;
    cin>>cas;
    while(cas--){
        cin>>length;
        c1=c2=0;
        while(length--){
            cin>>s;
            if(s=="HH") c1++;
            else if(s=="MM") c2++;
        }
        if(c1==c2) cout<<"POSIBLE\n";
        else cout<<"IMPOSIBLE\n";
    }
    return 0;
}

