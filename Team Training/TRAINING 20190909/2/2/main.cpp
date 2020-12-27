//  2
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
#include <utility>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<int,int> pii;
int main(int argc, const char * argv[]) {
	pii a,b;
	int ca;
	cin>>ca;
	while(ca--){
		cin>>a.fi>>a.se;
		cin>>b.fi>>b.se;
		if(a.fi>a.se)swap(a.fi,a.se);
		if(b.fi>b.se)swap(b.fi,b.se);
		if(a>b)swap(a,b);
		cout<<((a.se>b.fi)? "SOLAPADOS\n":"SEPARADOS\n");
	}
	return 0;
}
