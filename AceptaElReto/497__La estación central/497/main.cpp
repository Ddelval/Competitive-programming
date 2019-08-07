// AceptaElReto 497:  La estación central
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
#include <stdio.h>
#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(int j=0;j<width;j++){if(arr[i][j]==INT_MAX)printf(" inf ");else printf("%4d ",arr[i][j]);}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<long,long> ii;
typedef long long ll;
vector<vector<long>> lines;
vector<long> eq;
long ady[205][205];
long* repeated;
map<long,long> equivr;
map<long,long> equivl;
long mapcounter;

long indice(long centrales){
    long i,j,k,minimo,iminimo;
    
    minimo=INT_MAX;
    
    for(k=0;k<centrales;++k){
        for(i=0;i<centrales;++i){
            for(j=0;j<centrales;++j){
                ady[i][j]=min((ll)ady[i][j],(ll)((ll)ady[i][k]+(ll)ady[k][j]));
            }
        }
    }
    //echo_tablero(6,6,ady);
    for(i=0;i<centrales;++i){
        for(j=1;j<centrales;++j){
            ady[i][0]+=ady[i][j];
        }
    }
    
    for(i=0;i<centrales;++i){
        if(ady[i][0]<minimo){
            minimo=ady[i][0];
            iminimo=i;
        }
    }
    
    return iminimo;
}

int main(){
    ios::sync_with_stdio(false);
    long n,l;
    long dat;
    long pimp;
    long distance;
    while(cin>>n>>l&&n){
        equivr.clear();
        equivl.clear();
        eq.clear();
        vector<long> vi;
        lines.assign(l,vi);
        repeated=(long*)malloc((n+5)*sizeof(long));
        for(int i=0;i<=n;++i){
            repeated[i]=0;
        }
        for(int i=0;i<l;++i){
            while(cin>>dat&&dat){
                lines[i].push_back(dat);
                if(repeated[dat]==1){
                    repeated[dat]=2;
                    eq.push_back(dat);
                }
                else if (!repeated[dat]){
                    repeated[dat]=1;
                }
            }
        }
        sort(eq.begin(),eq.end());
        mapcounter=0;
        for(int i=0;i<eq.size();++i){
            equivr.insert(mp(eq[i],mapcounter));
            equivl.insert(mp(mapcounter,eq[i]));
            mapcounter++;
            for(int j=0;j<eq.size();j++){
                ady[i][j]=INT_MAX;
            }
        }
        long a,b;
        for(int i=0;i<l;++i){
            pimp=distance=-1;
            for(int j=0;j<lines[i].size();++j){
                if(repeated[lines[i][j]]==2){
                    if(pimp!=-1&&pimp!=lines[i][j]){
                        a=equivr[lines[i][j]];
                        b=equivr[pimp];
                        if(ady[b][a]!=INT_MAX){
                            if(ady[b][a]>distance){
                                ady[b][a]=distance;
                                ady[a][b]=distance;
                            }
                        }
                        else{
                            ady[b][a]=distance;
                            ady[a][b]=distance;
                        }
                        
                    }
                    pimp=lines[i][j];
                    distance=0;
                }
                distance++;
            }
            
        }
        cout<<sizeof(long);
        //echo_tablero(6,6,ady);
        if(eq.size()==1){
            cout<<eq[0]<<"\n";
        }
        else{
           cout<<equivl[indice((long)eq.size())]<<"\n";
        }
        
    }
    
    return 0;
}
