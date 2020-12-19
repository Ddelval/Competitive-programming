//  A
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

struct Stair{
	int size;
	vi steps;
	Stair(int a,vi s){
		steps=s;
		size=a;
	}
};
bool match(Stair a,Stair b){
	if(abs(a.size-b.size)>2)return false;
	int i1;
	if(a.size==b.size){
		bool t1=true;
		bool t2=true;
		i1=0;
		while(i1<a.size-1){
			if(a.steps[i1]!=b.steps[i1+1]){
				t1=false;
				break;
			}
			i1++;
		}
		i1=0;
		while(i1<a.size-1){
			if(a.steps[i1+1]!=b.steps[i1]){
				t2=false;
				break;
			}
			i1++;
		}
		return t1||t2;
	}
	if(a.size<b.size){
		swap(a, b);
	}
	i1=0;
	while(i1<b.size){
		if(a.steps[i1+1]!=b.steps[i1]){
			return false;
		}
		i1++;
	}
	return true;
}
int main(void) {
	int a;
	a=1;
	vector<Stair> data;
	vector<int> v;
	cin>>a;
	while(a!=0){
		v.clear();
		while(a!=0){
			v.pb(a);
			cin>>a;
			
		}
		data.pb(Stair((int)v.size(),v));
		cin>>a;
	}
	int count=0;
	for(int i=0;i<data.size();++i){
		Stair a=data[i];
		vi coup=a.steps;
		reverse(coup.begin(), coup.end());
		Stair a2= Stair(a.size,coup);
		for(int j=i;j<data.size();++j){
			Stair b=data[j];
			if(match(b,a2))count++;
		}
	}
	cout<<count;
	return 0;
}
