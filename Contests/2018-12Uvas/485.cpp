#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;
int data[100];
int sum;
int l;
void sums(int n){
    if(n<0){
        return;
    }
    sum+=data[n];
    sums(n-1);
    
    cout<<sum;
    sum-=data[n];
    if(n!=l){
        cout<<" ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
        sum=0;
        l=n-1;
        sums(n-1);
        cout<<"\n";
    }
    
    return 0;
}

