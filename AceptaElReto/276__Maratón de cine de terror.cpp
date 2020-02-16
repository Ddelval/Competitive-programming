// AceptaElReto 276:  Maratón de cine de terror
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
vector <ii> films;

int main(){
    ios::sync_with_stdio(false);
    int n;
    int i,j;
    int h,m,d;
    char c;
    while(cin>>n && n){
        films.clear();
        for (i=0; i<n; i++) {
            cin>>h>>c>>m>>d;
            films.push_back(mp(60*h+m,60*h+m+d));
        }
        sort(films.begin(), films.end());
        
        int min;
        int minindex;
        int counter=0;
        int endtime=-10;
        minindex=-1;
        while(1){
            min=INT_MAX;
            
            for(j=minindex+1;j<n;++j){
                if(films[j].first>=endtime+10){
                    if(films[j].second<min){
                        min=films[j].second;
                        minindex=j;
                    }
                    else if(films[j].first>min) break;
                }
                
            }
            if(min!=INT_MAX){
                counter++;
                endtime=min;
            }
            else{
                break;
            }
        }
        cout<<counter<<"\n";
        
    }
    
    return 0;
}

