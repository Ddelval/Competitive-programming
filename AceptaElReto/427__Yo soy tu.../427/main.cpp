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
    string s1,s2;
    int length;
    cin>>length;
    for(int i=0;i<length;i++){
        cin>>s1;
        cin>>s2;
        if(s1=="Luke"&&s2=="padre"){
            cout<<"TOP SECRET\n";
        }
        else{
            cout<<s1<<", yo soy tu "<<s2<<"\n";
        }
    }
    return 0;
}

