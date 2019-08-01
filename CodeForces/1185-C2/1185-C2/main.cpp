//
//  main.cpp
//  1185-C2
//
//  Created by David del Val on 20/06/2019.
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

int times[101];

int main() {
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int sum;
    int count;
    int aux;
    int add;
    count=0;
    for(int i=0;i<n;++i){
        cin>>aux;
        sum=aux;
        count=0;
        for(int j=1;j<=100;++j){
            add=(m-sum)/j;
            if(!add)break;
            add=min(add,times[j]);
            sum+=add*j;
            count+=add;
        }
        if(i)cout<<" ";
        cout<<(i)-count;
        times[aux]++;
    }
    return 0;
}
