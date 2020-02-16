// AceptaElReto 230:  Desórdenes temporales
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
vector<int> tot;
ll merge(vector<int>&right,vector<int>&left,vector<int>&tofill){
    ll inver=0;
    int i,j,k;
    i=j=k=0;
    while(i<right.size()&&j<left.size()){
        if(right[i]<=left[j]){
            tofill[k]=right[i];
            inver+=j;
            i++;
        }
        else{
            tofill[k]=left[j];
            j++;
        }
        k++;
    }
    while(i<right.size()){
        tofill[k]=right[i];
        inver+=j;
        i++;
        k++;
    }
    while(j<left.size()){
        tofill[k]=left[j];
        j++;
        k++;
    }
    return inver;
    
}
ll split(vector<int> &tofill, int l, int r){
    ll inver=0;
    if(r-l<=1){
        tofill[0]=tot[l];
        return 0;
    }
    int nb = (r-l)/2+l;
    vector<int> right(r-nb);
    vector<int> left(nb-l);
    inver+=split(left,l,nb);
    inver+=split(right,nb,r);
    inver+=merge(left,right,tofill);
    return inver;
}

int main(){
    ios::sync_with_stdio(false);
    int length;
    while(cin>>length&&length){
        tot=vector<int>(length);
        vector<int>fill(length);
        for(int i=0;i<length;++i){
            cin>>tot[i];
        }
        
        cout<<split(fill,0,tot.size())<<"\n";
    }
    
    return 0;
}

