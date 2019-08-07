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
int n1[100],n2[100];
int res[105];
int l1,l2;
int lim;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    string s,s1;
    char c;
    int carry;
    int ndig;
    int p1,p2;
    getline(cin,s);
    cas=stoi(s);
    for(int m=0;m<cas;m++){
        p1=p2=0;
        cin>>s;
        cin>>s1;
        p1=(int)s.length();
        p2=(int)s1.length();
        lim=(int)min(s.length(),s1.length());
        carry=0;
        for(int i=1;i<=lim;i++){
            ndig=carry+(s[p1-i]-'0')*(s1[p2-i]-'0');
            res[i]=ndig%10;
            carry=ndig/10;
        }
        if(carry){
            lim=abs(p1-p2)-1;
            for(int i=0;i<lim;i++){
                cout<<'0';
            }
            cout<<carry;
        }
        else{
            lim=abs(p1-p2);
            for(int i=0;i<lim;i++){
                cout<<'0';
            }
        }
        lim=min(p1,p2);
        for(int i=lim;i>0;--i){
            cout<<res[i];
        }
        cout<<"\n";
    }
    return 0;
}

