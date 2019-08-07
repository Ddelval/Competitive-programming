#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
vector<int> primes;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    bool prime;
    long number;
    int lim;
    primes.push_back(2);
    for(int i=3;i<46341;i+=2){
        prime=true;
        for(int j=3;j<=sqrt(i);j++){
            if(!(i%j)){
                prime=false;
                break;
            }
        }
        if(prime){
            primes.push_back(i);
        }
    }
    cin>>cas;
    for(int i=0;i<cas;i++){
        cin>>number;
        lim=sqrt(number);
        if(lim==number){
            cout<<"1\n";
            continue;
        }
        for(int i=0;i<primes.size();i++){
            if(primes[i]>lim){
                break;
            }
            while(!(number%(primes[i]*primes[i]))){
                number/=(primes[i]*primes[i]);
            }
        }
        cout<<number<<"\n";
    }
    return 0;
}

