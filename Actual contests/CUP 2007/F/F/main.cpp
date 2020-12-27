//  F
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

pii change(char a,char b){
	int x,y;
	switch (a) {
		case 'S':
			y=3;
			break;
		case 'H':
			y=2;
			break;
		case 'D':
			y=1;
			break;
		case 'C':
			y=0;
			break;
	}
	switch (b) {
		case 'A':
			x=12;
			break;
		case 'K':
			x=11;
			break;
		case 'Q':
			x=10;
			break;
		case 'J':
			x=9;
			break;
		case '0':
			x=8;
			break;
		default:
			x=b-'2';
			break;
	}
	return mp(x,3-y);
}
pii arr[13][4];
bool visited[13][4];

void explore(int x, int y){
	if(visited[x][y])return;
	visited[x][y]=true;
	explore(arr[x][y].fi,arr[x][y].se);
	arr[x][y]=mp(x,y);
}
int main(void) {
	string s;
	while(true){
		for(int i=0;i<4;++i){
			for(int j=0;j<13;++j){
				if(cin>>s){}
				else return 0;
				arr[j][i]=change(s[0],s[1]);
				visited[j][i]=false;
				
			}
		}
		int counter=0;
		for(int i=0;i<4;++i){
			for(int j=0;j<13;++j){
				if(visited[j][i])continue;
				counter++;
				explore(j,i);
			}
		}
		cout<<counter<<"\n";
	}
	
	
	return 0;
}
