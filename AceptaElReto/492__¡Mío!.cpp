// AceptaElReto 492:  ¡Mío!
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

ll gcd(ll a,ll b){
    return b == 0 ? a : gcd(b, a % b);
}
ll gcda(ll a,ll b){
    if(a>=b) return gcd(a,b);
    else return gcd(b,a);
}
int main(){
    ios::sync_with_stdio(false);
    ll n1,n2,lim;
    ll aux,out;
    while(cin>>n1>>n2>>lim){
        if(!n1||!n2) break;
        aux=(n1*n2)/gcd(n1,n2);
        out=lim/aux;
        cout<<out<<"\n";
    }
    
    return 0;
}

