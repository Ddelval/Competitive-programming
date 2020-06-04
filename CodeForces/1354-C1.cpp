//  1354-C1.cpp
//  Created by David del Val on 03/06/2020
//
//

#include <bits/stdc++.h>
#include <cmath>


#define M_PI       3.14159265358979323846
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n*=2;
        double alf=M_PI/(n);
        double r=0.5/(sin(alf));
        double a=r*cos(alf);
        cout<<"r:"<<r<<" "<<"a:"<<a<<"\n";
        printf("%.9lf\n",2*a);
    }
    
    return 0;
}