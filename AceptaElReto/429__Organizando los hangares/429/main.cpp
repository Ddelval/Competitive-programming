// AceptaElReto 429:  Organizando los hangares
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
priority_queue<int> pq;
int main() {
    ios::sync_with_stdio(false);
    int n_hang;
    int n_av;
    int a_size;
    int h_size;
    int iter;
    bool fit;
    int new_value;
    while(cin>>n_hang&&n_hang){
        while(!pq.empty()){
            pq.pop();
        }
        for(int i=0;i<n_hang;i++){
            cin>>h_size;
            pq.push(h_size);
        }
        cin>>n_av;
        fit=true;
        for(iter=0;iter<n_av;iter++){
            cin>>a_size;
            new_value=pq.top()-a_size;
            if(new_value>=0){
                pq.pop();
                pq.push(new_value);
            }
            else{
                fit=false;
                break;
            }
        }
        for(iter++;iter<n_av;iter++){
            cin>>a_size;
        }
        if(fit){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
        
    }
    return 0;
}

