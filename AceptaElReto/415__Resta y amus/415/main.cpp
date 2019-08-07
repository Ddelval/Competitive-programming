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
    string s;
    int sum;
    while(cin>>s&&s!="0"){
        sum=0;
        for(int i=0;i<s.length();++i){
            sum+=s[i]-'0';
        }
        if(sum%9) cout<<"NO\n";

        else cout<<"SI\n";
    }
    return 0;
}

