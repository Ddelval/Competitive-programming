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

int main(){
    ios::sync_with_stdio(false);
    int td,ta,dd,da;
    int tiradas_d,tiradas_a;
    int tropas_con;
    vector<int> d;
    vector<int> a;
    int cursor;
    string in;
    int aux;
    while(cin>>td>>ta>>dd>>da){
        getline(cin,in);
        getline(cin,in);
        cursor=0;
        while(cursor<in.length()&&td&&ta){
            d.clear();
            a.clear();
            tiradas_d=min(dd,td);
            tiradas_a=min(ta,da);
            for(int i=0;i<tiradas_d;i++){
                aux=in[cursor]-'0';
                cursor+=2;
                d.push_back(aux);
            }
            for(int i=0;i<tiradas_a;i++){
                aux=in[cursor]-'0';
                cursor+=2;
                a.push_back(aux);
            }
            sort(d.begin(),d.end(),greater<int>());
            sort(a.begin(),a.end(),greater<int>());
            tropas_con=min(tiradas_a,tiradas_d);
            for(int i=0;i<tropas_con;++i){
                if(d[i]>=a[i]) ta--;
                else td--;
            }
        }
        cout<<td<<" "<<ta<<"\n";
    }
    
    return 0;
}
