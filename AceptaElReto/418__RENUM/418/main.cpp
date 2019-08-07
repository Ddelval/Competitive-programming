// AceptaElReto 418:  RENUM
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
int label[102];
int data[102]; //store 1 for goto, 2 for gosub, 3 for return
map<int,int> on;
int l_case=0;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int a,j;
    string s;
    cin>>cas;
    for(int i=0;i<cas;++i){
        on.clear();
        a=1;
        for(l_case=0;a;++l_case){
            cin>>a;
            if(!a) break;
            on.insert(make_pair(a,10*(l_case+1)));
            cin>>s;
            if(s.length()==4){
                data[l_case]=1;
                 cin>>label[l_case];
            }
            else if(s.length()==5){
                data[l_case]=2;
                 cin>>label[l_case];
            }
            else{
                data[l_case]=3;
            }
           
        }
        
        for(j=0;j<l_case;++j){
            cout<<10*(j+1);
            switch(data[j]){
                case 1: cout<<" GOTO ";cout<<on[label[j]]; break;
                case 2: cout<<" GOSUB ";cout<<on[label[j]]; break;
                case 3: cout<<" RETURN"; break;
            }
            cout<<"\n";
        }
        cout<<"---\n";
    }
    return 0;
}

