//  5
//	main.cpp
//  Created by David del Val on 09/09/2019
//
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <stdio.h>
#include <cmath>
#include <set>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

typedef long long ll;

int main(int argc, const char * argv[]) {
	long long q, dig, cont0, cont;
	string num;
	cin >> q;
	while(q--){
		cin >> num;
		cont0=0;
		cont=0;
		if(num=="0"){
			cout<<"COMPLETO"<<"\n";
			continue;
		}
		for(char d:num){
			if(d=='0'){
				cont0++;
			} else{
				cont=(cont+d-'0')%9;
			}
		}
		if(cont0>=2){
			if(cont==0){
				cout << "COMPLETO"<<"\n";
			} else{
				cout<<9-cont<<"\n";
			}
		}
		else if(cont0==1){
			if(cont==0){
				cout<<0<<"\n";
			} else{
				cout<<0<<9-cont<<"\n";
			}
		}else{
			if(cont==0){cout<<"00"<<"\n";
			}
			else{cout<<"00"<<9-cont<<"\n";
			}
		}
	}
	return 0;
}
