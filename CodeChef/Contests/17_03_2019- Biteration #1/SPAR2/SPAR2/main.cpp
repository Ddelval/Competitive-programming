
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
int arr[100000];
int main(){
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int a,l,r;
    double max;
    double s;
    double are;
    int candid;
    for(int i=0;i<q;++i){
        cin>>l>>r>>a;
        max=0;
        l--;
        r--;
        candid=-1;
        for(int j=l;j<=r;++j){
            if(arr[j]>=2*a) continue;
            s=a+((double)arr[j])/2;
            are=sqrt(s*(s-a)*(s-a)*(s-arr[j]));
            if(are>max){
                max=are;
                candid=arr[j];
            }
        }
        cout<<candid<<"\n";
    }
    
    return 0;
}
