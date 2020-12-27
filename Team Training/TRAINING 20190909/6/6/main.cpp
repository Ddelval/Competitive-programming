//  6
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
	ll N, n, m;
	double num;
	while(cin>>N&&N){
		n=0;
		m=0;
		ll l=0;
		for(int i=0;i<N;i++){
			cin>>num;
			if(num==0||num==1)l++;
			if((num>=1)||(num==0)){
				n++;
			}
			if(num<=1){
				m++;
			}
		}
		cout<<(m*(m-1)+n*(n-1)-(l*(l-1)))/2<<"\n";
	}
	return 0;
}
