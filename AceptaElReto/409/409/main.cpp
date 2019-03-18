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
    vector<int> vi;
    int cas,j,target,size,a,count;
    cin>>cas;
    for(int i=0;i<cas;++i){
        vi.clear();
        cin>>target>>size;
        vi.reserve(size);
        for(j=0;j<size;++j){
            cin>>a;
            vi.push_back(a);
        }
        if(target>size){
            cout<<"0\n";
            continue;
        }
        sort(vi.begin(),vi.end());
        target--;
        count=0;
        for(j=target;j<size;++j){
            if(vi[j]-vi[j-target]<=15){
                j+=target;
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}

