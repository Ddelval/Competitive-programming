#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    ll cost,prize,ammount;
    ll total,aux;
    while(cin>>cost>>prize>>ammount&&(cost||prize||ammount)){
        if(cost<=prize&&ammount>=cost){
            cout<<"RUINA\n";
        }
        else if (!prize){
            cout<<ammount<<" "<<ammount<<"\n";
        }
        else if(cost<=prize && cost>ammount){
            cout<<ammount<<" "<<ammount<<"\n";
        }
        else{
            total=ammount;
            while(ammount>=cost){
                aux=(ammount/cost)*prize;
                total+=aux;
                aux+=ammount%cost;
                ammount=aux;
            }
            cout<<total<<" "<<ammount<<"\n";
            
        }
    }
    return 0;
}

