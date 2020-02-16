//
//  main.cpp
//  1176-C
//
//  Created by David del Val on 09/06/2019.
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
vector<int> vi;
int sear[]={4,8,15,16,23,42};
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        int a;
        int disc=0;
        int count4,count8,count16,count15,count23,count42;
        vi.clear();
        vi.reserve(n);
        count4=count8=count16=count15=count23=count42=0;
        for(int i=0;i<n;++i){
            cin>>a;
            if(a==4){
                count4++;
            }
            else if(a==8){
                if(count4){
                    count4--;
                    count8++;
                }
                else{
                    disc++;
                }
            }
            else if(a==15){
                if(count8){
                    count8--;
                    count15++;
                }
                else{
                    disc++;
                }
            }
            else if(a==16){
                if(count15){
                    count15--;
                    count16++;
                }
                else{
                    disc++;
                }
            }
            else if(a==23){
                if(count16){
                    count16--;
                    count23++;
                }
                else{
                    disc++;
                }
            }
            else if(a==42){
                if(count23){
                    count23--;
                }
                else{
                    disc++;
                }
            }
        }
        cout<<disc+count4+2*count8+3*count15+4*count16+5*count23;
        
    }
    
    return 0;
}
