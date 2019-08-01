//  B
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
typedef pair<double, double> pii;
typedef pair<ll, ll> pll;

typedef pair<pii,int> vote;


bool win(int oa,int ob,int oc,int s){
	int sx[3];
	sx[0]=sx[1]=sx[2]=0;
	vote a,b,c;
	
	a.fi.fi=a.fi.se=oa;
	a.se=0;
	
	b.fi.fi=b.fi.se=ob;
	b.se=1;
	
	c.fi.fi=c.fi.se=oc;
	c.se=2;
	
	vector<vote> dat;
	dat.pb(a); dat.pb(b); dat.pb(c);
	for(int i=0;i<s;++i){
		sort(dat.begin(),dat.end(),greater<vote>());
		sx[dat[0].se]++;
		dat[0].fi.fi=dat[0].fi.se/(sx[dat[0].se]+1);
	}
	return sx[0]+sx[1]>sx[2];
}


int main(void) {
	int a,b,c,s;
	cin>>a>>b>>c>>s;
	while(a || b || c || s){
		for(int i=1;i<=max(a,b);++i){
			if(i<=b){
				if(win(a+i,b-i,c,s)){
					cout<<"from B to A, "<<i<<" vote"<<(i>1? "s":"")<<"\n";
					break;
				}
			}
			
			if(i<=a){
				if(win(a-i,b+i,c,s)){
					cout<<"from A to B, "<<i<<" vote"<<(i>1? "s":"")<<"\n";
					break;
				}
			}
			
		}
		cin>>a>>b>>c>>s;
	}
	
	
	
	return 0;
}
