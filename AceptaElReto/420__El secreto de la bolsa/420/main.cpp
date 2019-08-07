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
string data;
int target;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int endsum,sum,counter;
    cin>>cas;
    data.reserve(250000);
    for(int i=0;i<cas;++i){
        cin>>target;
        cin>>data;
        endsum=0;
        sum=0;
        counter=0;
        for(int i=0;i<data.size();++i){
            sum+=data[i]-'0';
            if(sum==target){
                counter++;
            }
            else if(sum>target){
                while(sum>target){
                    sum-=(data[endsum]-'0');
                    endsum++;
                }
                if(sum==target){
                    counter++;
                }
            }

        }
        cout<<counter<<"\n";
    }
    return 0;
}

