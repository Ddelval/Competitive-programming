//  3
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

int main(int argc, const char * argv[]) {
	int P, L, A, contador;
	int piso;
	char letra;
	int v[30][26];
	
	cin >> P;
	cin >> L;
	cin >> A;
	
	while((P!=0)&&(L!=0)&&(A!=0)){
		
		contador=0;
		
		for(int i=0;i<30;i++){
			for(int j=0;j<26;j++){
				v[i][j]=0;
			}
		}
		for(int i=0;i<A;i++){
			cin >> piso;
			cin >> letra;
			
			if(v[piso-1][letra-'A']==0){
				v[piso-1][letra-'A']=1;
				contador++;
			}
		}
		
		if(contador>=(P*L+1)/2){
			cout<<"EMPEZAMOS"<< "\n";
		} else{
			cout<<"ESPERAMOS"<<"\n";
		}
		
		cin >> P;
		cin >> L;
		cin >> A;
	}
	
	return 0;
}
