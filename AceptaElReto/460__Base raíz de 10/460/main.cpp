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

int main() {
    ios::sync_with_stdio(false);
    string in;
    string out;
    int len;
    while(cin>>in){
        if(in.length()==1){
            cout<<in<<"\n";
            continue;
        }
        len=(int)in.length();
        for(int i=0;i<len-1;i++){
            cout<<in[i];
            cout<<"0";
        }
        cout<<in[len-1]<<"\n";
    }
    return 0;
}

