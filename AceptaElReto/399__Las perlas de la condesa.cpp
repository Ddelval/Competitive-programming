// AceptaElReto 399:  Las perlas de la condesa
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
vector<int> perl;
int main() {
    ios::sync_with_stdio(false);
    int n,i;
    int prev;
    bool no;
    while(cin>>n&&n){
        perl.clear();
        perl.push_back(n);
        while(cin>>n&&n){
            perl.push_back(n);
        }
        sort(perl.begin(),perl.end());
        if(perl.size()==1){
            cout<<perl[0]<<"\n";
        }
        else if(!(perl.size()%2)){
            cout<<"NO\n";
        }
        else{
            n=perl[0];
            i=1;
            no=false;
            while(i<perl.size()-1){
                if(perl[i]!=n){
                    no=true;
                    break;
                }
                i++;
                n=perl[i];
                i++;
            }
            if(no){
                cout<<"NO\n";
                continue;
            }
            for(i=0;i<perl.size()-1;i+=2){
                cout<<perl[i]<<" ";
            }
            cout<<perl[perl.size()-1];
            for(i=(int)perl.size()-2;i>=0;i-=2){
                cout<<" "<<perl[i];
            }
            cout<<"\n";
        }
        
    }
    return 0;
}

