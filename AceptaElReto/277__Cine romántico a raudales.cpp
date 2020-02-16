// AceptaElReto 277:  Cine romántico a raudales
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
vector<ii> activities;
int dp[1000];
int len;
int choose (int currind,int currentstart){
    int n1,n0;
    if(currind<0) return 0;
    int newgain=0;
    for(;currind>=0;currind--){
        if(activities[currind].first<=currentstart){
            if(dp[currind]){
                return dp[currind];
            }
            else{
                n1=choose(currind-1,activities[currind].first-activities[currind].second)+activities[currind].second-10;
                n0=choose(currind-1,currentstart);
            }
            
            newgain=max(n1,n0);
            break;
        }
    }
    return dp[currind]=newgain;
    
}
int main() {
    ios::sync_with_stdio(false);
    
    int h,m,d;
    char c;
    while(cin>>len&&len){
        activities.clear();
        for(int i=0;i<1000;++i){
            dp[i]=0;
        }
        for(int i=0;i<len;++i){
            cin>>h>>c>>m>>d;
            activities.push_back(mp(h*60+m+d+10,d+10));
        }
        sort(activities.begin(),activities.end());
        cout<<choose(len-1, INT_MAX)<<"\n";
        
    }
    return 0;
}
