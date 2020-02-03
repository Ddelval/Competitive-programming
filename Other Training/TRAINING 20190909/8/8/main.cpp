//  8
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
#include <map>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

int main(int argc, const char * argv[]) {
	map<string,int> abc;
	int i=0;
	for(char c='a';c<='z';c++){
		string a;
		a.pb(c);
		abc[a]=i;
		i++;
		if(c=='c'){
			abc["ch"]=i;
			i++;
		}
		if(c=='l'){
			abc["ll"]=i;
			i++;
		}
	}
	string s1,s2;
	while(cin>>s1>>s2){
		int i;
		vector<string> v1,v2;
		
		for(i=0;i<s1.length()-1;++i){
			string a=s1.substr(i,2);
			if(a=="ch"||a=="ll"){v1.pb(a); i++;}
			else v1.pb(s1.substr(i,1));
		}
		if(i<(int)s1.length())v1.pb(s1.substr(i,1));
		
		for(i=0;i<s2.length()-1;++i){
			string a=s2.substr(i,2);
			if(a=="ch"||a=="ll"){v2.pb(a); i++;}
			else v2.pb(s2.substr(i,1));
		}
		if(i<(int)s2.length())v2.pb(s2.substr(i,1));
		i=0;
		int res=1;
		while(i<v1.size()||i<v2.size()){
			if(!(i<v1.size())){
				res=1;
				break;
			}
			if(!(i<v2.size())){
				res=2;
				break;
			}
			if(abc[v1[i]]>abc[v2[i]]){
				res=2;
				break;
			}
			if(abc[v1[i]]<abc[v2[i]]){
				res=1;
				break;
			}
			i++;
		}
		if(res==1){
			cout<<s1<<"\n";
		}
		else cout<<s2<<"\n";
	}
	return 0;
}
