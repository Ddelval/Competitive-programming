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
    int p2;
    int p1;
    char c;
    while(cin>>p1>>p2 && p1&&p2){
        c=('h'+1-p1);
        cout<<c<<p2<<"\n";
    }
    return 0;
}

