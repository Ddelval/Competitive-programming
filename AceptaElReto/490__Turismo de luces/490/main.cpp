// AceptaElReto 490:  Turismo de luces
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
ll maxim;
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    int prev,tmp;
    ll sum;
    while(cin>>n>>k){
        vi= vector<int>(n-1);
        cin>>prev;
        for(int i=1;i<n;++i){
            cin>>tmp;
            vi[i-1]=tmp-prev;
            prev=tmp;
        }
        k--;
        sum=0;
        for(int i=0;i<k;++i){
            sum+=vi[i];
        }
        maxim=sum;
        if(-sum>maxim) maxim=-sum;
        for(int i=k;i<vi.size();++i){
            sum-=(vi[i-k]);
            sum+=(vi[i]);
            if(sum>maxim) maxim=sum;
            if(-sum>maxim) maxim=-sum;
        }
        cout<<maxim<<"\n";
        
    }
    
    
    
    
    
    
    
    
    return 0;
}

