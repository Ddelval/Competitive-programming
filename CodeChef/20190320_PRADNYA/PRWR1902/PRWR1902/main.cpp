
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    while(cas--){
        int f,s1,s2;
        cin>>f>>s1>>s2;
        int q;
        cin>>q;
        while(q--){
            int i1,i2,out;
            cin>>i1>>i2;
            if((i1==s1&&i2==s2)||(i1!=s1&&i2!=s2)){
                out=f;
            }
            else{
                out=!f;
            }
            if(out){
                cout<<"ON\n";
            }
            else{
                cout<<"OFF\n";
            }
        }
    }
    
    return 0;
}
