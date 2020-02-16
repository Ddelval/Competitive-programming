// AceptaElReto 486:  ¡Hay que compartir!
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <stdio.h>
#include <math.h>
using namespace std;
pair<long,long> data[10000];
long mcd(long a,long b){
    if (b == 0)
        return a;
    return mcd(b, a % b);
}
long long int mcda(long long int a,long long int b){
    long long int t = a*b;;
    return t/mcd(a,b);
}
int main() {
    int com;
    int a,b;
    long multi;
    long up;
    while(cin>>com&&com){
        multi=1;
        for(int i=0;i<com;i++){
            scanf("%d/%d",&a,&b);
                if(multi>b){
                    multi=mcda(multi, b);
                }
                else{
                    multi=mcda(b, multi);
                }
            
            data[i].first=a;
            data[i].second=b;
        }
        up=0;
        for(int i=0;i<com;i++){
            up+=data[i].first*(multi/data[i].second);
        }
        cout<<multi-up<<"\n";
    }
    return 0;
}

