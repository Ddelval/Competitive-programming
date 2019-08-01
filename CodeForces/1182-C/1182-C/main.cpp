//
//  main.cpp
//  1182-C
//
//  Created by David del Val on 11/06/2019.
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
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,char> word;
typedef pair<pair<word,word>,pair<int,int>> couple;
vector<pair<pair<word,bool>,int>> data;
vector<couple> t1;
vector<couple> t2;
vector<pair<couple,couple>> result;
vector<string> rawdata;
int main(){
    ios::sync_with_stdio(false);
    int n;
    string s;
    int vcount;
    char lastw;
    word w;
    while(cin>>n){
        t1.clear();
        t2.clear();
        data.clear();
        result.clear();
        rawdata.clear();
        data.reserve(n);
        for(int i=0;i<n;++i){
            cin>>s;
            vcount=0;
            lastw='a';
            for(char a:s){
                if(a=='a'||a=='e'||a=='o'||a=='i'||a=='u'){
                    vcount++;
                    lastw=a;
                }
            }
            w.first=vcount;
            w.second=lastw;
            data.push_back({{w,false},i});
            rawdata.push_back(s);
        }
        if(n<4){
            cout<<"0\n";
            continue;
        }
        sort(data.begin(),data.end());
        //Search for type 2
        t1.reserve(n/2+1);
        t2.reserve(n/2+1);
        for(int i=1;i<data.size();++i){
            word w1=data[i-1].first.first;
            word w2=data[i].first.first;
            if(w1.first==w2.first&&w2.second==w1.second){
                t2.push_back({{w1,w2},{data[i-1].second,data[i].second}});
                data[i].first.first.first=-1;
                data[i-1].first.first.first=-1;
                data[i-1].first.second=true;
                data[i].first.second=true;
                i++;
            }
        }
        sort(data.begin(),data.end());
        for(int i=1;i<data.size();++i){
            if(data[i].first.first.first==-1) continue;
            word w1=data[i-1].first.first;
            word w2=data[i].first.first;
            if(w1.first==w2.first&&!data[i-1].first.second&&!data[i].first.second){
                t1.push_back({{w1,w2},{data[i-1].second,data[i].second}});
                i++;
            }
        }
        int i1,i2;
        i1=i2=0;
        while(i1<t1.size()||i2<t2.size()){
            if(i1<t1.size()&&i2<t2.size()){
                result.push_back({t1[i1],t2[i2]});
                i1++;
                i2++;
            }
            else if(i2<((int)t2.size()-1)){
                result.push_back({t2[i2],t2[i2+1]});
                i2+=2;
            }
            else{
                if(i1<t1.size()){
                    i1++;
                }
                else if(i2<t2.size()){
                    i2++;
                }
            }
        }
        cout<<result.size()<<"\n";
        if(result.size()){
            for(int i=0;i<result.size();++i){
                cout<<rawdata[result[i].first.second.first]<<" "<<rawdata[result[i].second.second.first]<<"\n";
                cout<<rawdata[result[i].first.second.second]<<" "<<rawdata[result[i].second.second.second]<<"\n";
            }
        }
        
        
    }
    
    return 0;
}
