//  7
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
	int n;
	cin>>n;
	while(n--){
		int ma=0;
		int counter=0;
		string s;
		cin>>s;
		for(char c:s){
			if(c=='I')counter++;
			else counter--;
			if(counter<0){counter=0; ma++;}
			ma=max(counter,ma);
		}
		cout<<ma<<"\n";
	}
	return 0;
}
