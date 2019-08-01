//
//  main.cpp
//  1185-D
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
vector<ii> in;
int n;
int main() {
    ios::sync_with_stdio(false);
    int aux;
    cin>>n;
    in.reserve(n);
    for(int i=0;i<n;++i){
        cin>>aux;
        in.push_back({aux,i});
    }
    if(n<=3){
        cout<<"1";
        return 0;
    }
    sort(in.begin(), in.end());
    int candid=in[1].first-in[0].first;
    int selected=-10;
    bool elim=false;
    bool failed=false;
    for(int i=1;i<n;++i){
        if(in[i].first-in[i-1].first!=candid){
            if (i==selected+1) continue;
            if(elim){
                failed=true;
                break;
            }
            if(i==n-2){
                if(in[i+1].first-in[i-1].first==candid){
                    selected=i;
                    elim=true;
                }
                else if(in[n-2].first-in[n-3].first==candid){
                    selected=n-1;
                    elim=true;
                }
                else{
                    failed=true;
                    break;
                }
            }
            else if(!elim&&(i==n-1||in[i+1].first-in[i-1].first==candid)){
                selected=i;
                elim=true;
            }
            else{
                failed=true;
                break;
            }
        }
    }
    if(!elim&&!failed){
        cout<<in[0].second+1;
    }
    else if(elim&&!failed){
        cout<<in[selected].second+1;

    }
    else{
        elim=failed=false;
        selected=-10;
        candid=in[n-1].first-in[n-2].first;
        for(int i=n-1;i>0;--i){
            if (i==selected) continue;
            if(in[i].first-in[i-1].first!=candid){
                if(elim){
                    failed=true;
                    break;
                }
                if(i==1){
                    if(in[i+1].first-in[i-1].first==candid){
                        selected=i;
                        elim=true;
                    }
                    else if(in[2].first-in[1].first==candid){
                        selected=0;
                        elim=true;
                    }
                    else{
                        failed=true;
                        break;
                    }
                }
                /*
                else if(in[i+1].first-in[i-1].first==candid){
                    selected=i;
                    elim=true;
                }*/
                else if(i==1||in[i].first-in[i-2].first==candid){
                    selected=i-1;
                    elim=true;
                }
                else{
                    failed=true;
                    break;
                }
            }
        }
        if(failed){
            cout<<"-1";
        }
        else if (elim){
            cout<<in[selected].second+1;
        }
        else{
            cout<<in[0].second+1;
        }
    }
    
    
    return 0;
}
