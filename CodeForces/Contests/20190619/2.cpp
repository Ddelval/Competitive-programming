//
//  main.cpp
//  2
//
//  Created by David del Val on 19/06/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

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
#include <string.h>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    for(int z=0;z<cas;++z){
        string s1,s2;
        cin>>s1>>s2;
        char pc=s2[0];
        int it=0;
        bool flag=false;
        if(s1[0]!=s2[0]){
            cout<<"NO\n";
            continue;
        }
        int i=0;
        while(it!=s1.length()-1&&s1[it]==s1[it+1]&&s2[i]==s2[i+1]){it++; i++;}
        i++;
        for(;i<s2.length();++i){
            if(s2[i]!=pc){
                pc=s2[i];
                it++;
                while(it!=s1.length()-1&&s1[it]==s1[it+1]&&s2[i]==s2[i+1]){it++; i++;}
            }
            if(it>=s1.length()||s1[it]!=s2[i]){
                flag=true;
                break;
            }
        }
        if(flag||it!=s1.length()-1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}

