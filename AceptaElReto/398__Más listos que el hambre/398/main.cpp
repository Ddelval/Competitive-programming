#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <utility>
#include <math.h>
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef pair <int,int> ii;
int bot_pos[105][2];
int bot;
int n_delay;
map<pair<int,ii>,int> DP;
int ab(int a){
    if(a<0) return -a;
    return a;
}
int maxi(int a, int b){
    if(a>b) return a;
    return b;
}
int dist(int n1,int n2){
    return ab(bot_pos[n1][0]-bot_pos[n2][0])+ab(bot_pos[n1][1]-bot_pos[n2][1]);
}
int send(int r1,int r2,int delay){
    int n_delay;
    if(r1==bot+1){ //When r1 arrives to the exit, we have to send the second one there
        return maxi(delay, dist(r2,bot+1));
    }
    if(DP.count(make_pair(r1,make_pair(r2,delay)))){
        return DP[make_pair(r1,make_pair(r2,delay))];
    }
    n_delay=maxi(dist(r2,r1+1)-delay,0);
    //cout<<r1<<" "<<r2<<" "<<delay<<":"<<n_delay<<"\n";
    return DP[make_pair(r1,make_pair(r2,delay))]=min(send(r1+1,r2,delay+dist(r1,r1+1)),delay+send(r1+1,r1,n_delay));
    
}
int main() {
    // ios::sync_with_stdio(false);
    int w,h;
    bot_pos[0][0]=1;
    bot_pos[0][1]=1;
    while(cin>>h){
        cin>>w>>bot;
        DP=map<pair<int,ii>,int>();
        
        bot_pos[bot+1][0]=w;
        bot_pos[bot+1][1]=h;
        if(!bot){
            //If there is no button, they can go straight to the exit
            cout<<(dist(0,1)+1)<<"\n";
            continue;
        }
        for(int i=1;i<=bot;++i){
            cin>>bot_pos[i][1]>>bot_pos[i][0];
        }
        cout<<(send(1,0,dist(0,1))+1)<<"\n";
        /*for(auto it= DP.begin();it!=DP.end();it++){
            cout<<it->first.first<<" "<<it->first.second.first<<" "<<it->first.second.second<<" : "<<it->second<<"\n";
        }*/
    }
    return 0;
}
