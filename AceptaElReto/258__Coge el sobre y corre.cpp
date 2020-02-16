// AceptaElReto 258:  Coge el sobre y corre
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
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> ii;
ii max;
int buffer[200000];
deque<int> Qi;
vector<int> Data;
int cursor;
int main() {
    ios::sync_with_stdio(false);
    int length_of_line,i;
    int val;
    int envelopes_to_get;
    while(cin>>length_of_line>>envelopes_to_get&&length_of_line){
        Qi.clear();
        Data.clear();
        Data.reserve(length_of_line);
        for(i=0;i<length_of_line;i++){
            cin>>val;
            Data.push_back(val);
        }
        for(i=0;i<envelopes_to_get;++i){
            while(!Qi.empty()&&Data[i]>=Data[Qi.back()]){
                Qi.pop_back();
            }
            Qi.push_back(i);
        }
        for(;i<length_of_line;++i){
            cout<<Data[Qi.front()]<<" ";
            while(!Qi.empty()&&Qi.front()<=i-envelopes_to_get){
                Qi.pop_front();
            }
            while(!Qi.empty()&&Data[i]>=Data[Qi.back()]){
                Qi.pop_back();
            }
            Qi.push_back(i);
        }
        cout<<Data[Qi.front()]<<"\n";
    }
    
    return 0;
}

