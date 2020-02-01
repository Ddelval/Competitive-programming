//  4
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


vector<pair<int, int>> v;
int main() {
	ll i, n, c, t, sc, st, sum;
	pair<int, pair<int, int>> u;
	
	
	while(true) {
		cin >> n;
		v.resize(n);
		if(n == 0) return 0;
		cin >> c >> t;
		for(i = 0; i < n; ++i) cin >> v[i].fi;
		for(i = 0; i < n; ++i) cin >> v[i].se;
		priority_queue<pair<int, pair<int, int>>> pc, pt;
		sc = st = 0;
		for(i = 0; i < n; ++i) {
			if(v[i].fi < v[i].se) {++sc; pc.push(mp(v[i].fi - v[i].se, v[i]));}
			else {++st; pt.push(mp(v[i].se - v[i].fi, v[i]));}
		}
		//cout << pc.size() << " .. " << pt.size() << endl;
		while(sc < c) {
			u = pt.top();
			pt.pop();
			pc.push(mp(u.se.fi - u.se.se, u.se));
			++sc;
		}
		while(st < t) {
			u = pc.top();
			pc.pop();
			pt.push(mp(u.se.se - u.se.fi, u.se));
			++st;
		}
		sum = 0;
		while(pt.empty() == false) {
			sum += pt.top().se.se;
			pt.pop();
		}
		while(pc.empty() == false) {
			sum += pc.top().se.fi;
			pc.pop();
		}
		cout << sum << "\n";
		
	}
	
	
	
	return 0;
}

/*
5
3 2
1 8 8 1 1
8 9 9 20 20
*/
