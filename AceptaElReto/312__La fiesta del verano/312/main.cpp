#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
ll aux;
ll gcd(ll a,ll b){
    aux=a%b;
    if(aux) return gcd(b,aux);
    else return b;
}
ll s_gcd(ll a, ll b){
    if(a>=b)return gcd(a,b);
    else return gcd(b,a);
}
int main() {
    ios::sync_with_stdio(false);
    ll number1,number2;
    ll sum;
    while(cin>>number1&&number1){
        sum=number1;
        while(cin>>number2&&number2){
            sum+=number2;
            number1=gcd(number1,number2);
        }
        cout<<sum/number1<<"\n";
    }
    return 0;
}

