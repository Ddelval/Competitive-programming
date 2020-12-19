#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;


int main(){
    string s;
    int n, m, c;

    while(cin >> s){
    n=0;
    m=0;
    c=0;

    while(s[m]!=0){
        m++;
    }

    for(int i=0;i<m;i++){
        if(('a'<=s[i])&&(s[i]<='z')){
            n=n+(s[i]-'a')+1;
        } else{
            n=n+(s[i]-'A')+27;
        }

    }

    for(int p=2;p<50;p++){
        if(p<n){
            if((n%p)==0){
                c=1;
            }
        }
    }

    if(c==1){
        cout << "It is not a prime word." << "\n";
    } else{
        cout << "It is a prime word." << "\n";
    }
    }

    

    return 0;
}