//  H
//	main.cpp
//  Created by David del Val on 31/07/2019
//
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define echo(x) cout << #x << ":" << x << endl;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int DP[1005][10005];

int main(void) {
	
	int W,n;
	while(cin>>W>>n&&(W||n)){
		vi data;
		data.reserve(n);
		int a;
		data.pb(0);
		for(int i=0;i<n;++i){
			cin>>a;
			data.pb(a);
			DP[i][0]=0;
		}
		DP[n][0]=0;
		for(int j=0;j<=W;++j){
			DP[0][j]=0;
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<=W;++j){
				if(data[i]>j) DP[i][j]=DP[i-1][j];
				else{
					DP[i][j]=max(DP[i-1][j],DP[i-1][j-data[i]]+data[i]);
				}
			}
		}
		cout<<W-DP[n][W]<<"\n";
		
		
		
		
		
	}
	
	
	
	return 0;
}
