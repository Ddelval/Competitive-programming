// UVa Online Judge 11054: Wine trading in Gergovia
//  11054
//  Created by David del Val on 20/02/2019
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

    int n;
    while(cin>>n&&n){
        ll cost=0;
        int a;
        ll cval=0;
        for(int i=0;i<n;++i){
            cin>>a;
            cval+=a;
            cost+=abs(cval);
        }
        cout<<cost<<"\n";



    }

    return 0;
}