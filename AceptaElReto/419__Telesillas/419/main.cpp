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
    vector<int>v;
    int maxw, users,i;
    int sillas,assigned;
    int cb,ce;
    while(cin>>maxw>>users&&maxw&&users){
        v.assign(users,0);
        for(i=0;i<users;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.begin()+users);
        cb=0;
        ce=users-1;
        sillas=0;
        assigned=0;
        while(cb<ce){
            if(v[ce]+v[cb]<=maxw){
                ce--;
                cb++;
                assigned+=2;
            }
            else{
                ce--;
                assigned++;
            }
            sillas++;
        }
        sillas+=(users-assigned);
        cout<<sillas<<"\n";
    }
    return 0;
}

