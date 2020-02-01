#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define fi first
#define se second
#define ll long long 

#define ma 1005
int m[ma][ma];
int check[ma][ma];
int n;
bool multipyl(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int add=0;
            for(int k=0;k<n;++k){
                add+=m[i][k]*m[k][j];
            }
            if(add!=check[i][j])return false;
        }
    }
    return true;
}
void read(int dest[ma][ma]){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>dest[i][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n&&n){
        read(m);
        read(check);
        if(multipyl())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}