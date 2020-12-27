//  1
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
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

typedef long long ll;

int main() {
	// insert code here...
	ll tt, m, M;
	string mat, s;
	
	cin >> tt;
	
	while(tt--) {
		
		cin >> mat;
		m = M = 0;
		mat = mat.substr(4, 3) + mat.substr(0, 4);
		//cout << mat << endl;
		while(true) {
			cin >> s;
			if(s == "0") break;
			s = s.substr(4, 3) + s.substr(0, 4);
			//cout << s << endl;
			if(mat < s) ++m;
			else ++M;
		}
		
		cout << M << " " << m << "\n";
	}
	
	return 0;
}
