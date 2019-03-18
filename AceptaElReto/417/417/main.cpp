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
#define dif 'a'-'A'
using namespace std;
bool ady[200][200];
int main() {
    ios::sync_with_stdio(false);
    string s;
    int i,j,a,l;
    int sublength,times;
    int totallength;
    bool bad;
    int pl=0;
    while(cin>>s){
        //Clean
        l=(int)s.length();
        for(i=0;i<pl;++i){
            for(j=0;j<pl/2+1;++j){
                ady[i][j]=false;
            }
        }
        //Go to uppercase
        for(i=0;i<l;++i){
            if(s[i]>='a'){
                s[i]-=dif;
            }
        }
        //Fill matrix
        for(i=0;i<l;++i){
            for(j=0;j<(l/2)+1;++j){
                if(s[i]==s[j]){
                    ady[i][j]=true;
                }
                
            }
        }
        //Search through the matrix;
        totallength=l;
        for(i=1;i<l;++i){
            if(ady[0][i]){
                sublength=i;
                if(sublength>totallength){
                    continue;
                }
                times=(int)l/sublength;
                if(times*sublength!=l){
                    continue;
                }
                times--;
                bad=false;
                for(j=0;j<times&&!bad;++j){
                    for(a=i+j*sublength;a<i+(j+1)*sublength&&!bad;++a){
                            if(!ady[a][a-i-j*sublength]){
                                bad=true;
                            }
                        
                    }
                }
                if(!bad){
                    totallength=min(totallength,sublength);
                }

            }
        }
        pl=l;
        cout<<totallength<<"\n";
    }
    return 0;
}

