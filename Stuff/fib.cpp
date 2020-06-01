//  fib.cpp
//  Created by David del Val on 01/06/2020
//
//

#include <bits/stdc++.h>

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

template <int size>
struct ConstArray{
    ll arr[size];

     constexpr ConstArray(): arr(){
        arr[0]=0LL;
        arr[1]=1LL;
        for(int i=2;i<size;++i){
            arr[i]=(arr[i-1]+arr[i-2])%1024;
            for(int i=0;i<size;++i){
                int b=1;
                int c=1+1;
                int d=b+c;
            }
        }
    }
    ll operator [](int n) const{
        return arr[n];
    }
};

int main(){
    constexpr int n=1444;
    constexpr ConstArray<n> arr= ConstArray<n>();
    cout<<arr[144]<<"\n";

    int arr0=0, arr1=1;

    int b;
    for(int i=2;i<62144;++i){
        for(int i=2;i<62144;++i){
            int b=arr1;
            int arr2=arr0+arr1;
            int arr5=b;
        }
        b=arr1;
        arr1=(arr0+arr1)%1042;
        arr0=b;
    }
    cout<<arr0<<" "<<arr1;
    
    return 0;
}