// AceptaElReto 107:  Aproximación de Gauss
//
//  main.cpp
//  107
//
//  Created by David del Val on 21/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//
#define USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <math.h>
char primes[100000]={0};
long primesbn[100000]={0};
using namespace std;
bool isPrime(long n){
    if(!primes[n]){
        bool prime=true;
        if(!(n%2)){
            primes[n]=-1;
            return false;
        }
        if(!(n%3)){
            primes[n]=-1;
            return false;
        }
        for(long i=5;i<=sqrt(n);i+=6){
            if(!(n%i)){
                prime=false;
                break;
            }
        }
        if(!prime){
            primes[n]=-1;
            return false;
        }
        for(long i=7;i<=sqrt(n);i+=6){
            if(!(n%i)){
                prime=false;
                break;
            }
        }
        if(prime){
            primes[n]=1;
        }
        else{
            primes[n]=-1;
        }
        return prime;
    }
    else{
        if(primes[n]==-1){
            return false;
        }
        else{
            return true;
        }
    }
    
}
long primesBeforeN(long n){
    if(!primesbn[n]){
        long counter=2;
        for(long i=5;i<=n;i+=6){
            if(isPrime(i)){
                counter++;
            }
        }
        for(long i=7;i<=n;i+=6){
            if(isPrime(i)){
                counter++;
            }
        }
        primesbn[n]=counter;
        return counter;
    }
    else{
        return primesbn[n];
    }
    
}
int main(int argc, char * argv[]) {
    // insert code here...
    
    double error;
    double allowed;
    long n=10;
    long m=3;
    cin>>n>>m;
    while(n||m){
        if(n==1){
            cout<<"Igual\n";
            cin>>n>>m;
            continue;
        }
        error=primesBeforeN(n)/(double)n;
        error-=(1/log(n));
        allowed=(1/pow(10,m));
        if(error<0){
            error=-error;
        }
        if(error==allowed){
            cout<<"Igual\n";
        }
        if(error<allowed){
            cout<<"Menor\n";
        }
        else{
            cout<<"Mayor\n";
        }
        cin>>n>>m;
        
    }
    return 0;
}
