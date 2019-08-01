//
//  main.cpp
//  1180-B
//
//  Created by David del Val on 24/06/2019.
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
vector<int> elements;
int n;
void coutarray(){
    for(int i=0;i<n;++i){
        if(i)cout<<" ";
        cout<<elements[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    int a;

    elements.reserve(n);
    for(int i=0;i<n;++i){
        cin>>a;
        if(a>=0){
            a=-a-1;
        }
        elements.push_back(a);
    }
    if(n%2){
        auto it =min_element(elements.begin(), elements.end());
        *it=-(*it)-1;
    }
    coutarray();
    
    return 0;
}
