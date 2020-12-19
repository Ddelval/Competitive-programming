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
#include <string.h>
#include <limits.h>
#include <fstream>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int v;
vector<string> lc(string &a,string &b,int len){
    int lim;
    vector<string> ve;
    string c;
    lim=(a.length()-len);
    for(int i=0;i<=lim;++i){
        c=a.substr(i,len);
        if(b.find(c)!=string::npos){
            ve.push_back(c);
        }
    }
    return ve;
}
int main() {
    ios::sync_with_stdio(false);
    ifstream in;
    ofstream out("/Users/daviddelval/Desktop/Out.txt");
    string s1,s2,s3,s4;
    vector<string> aux;
    vector<string> aux2;
    vector<string> aux3;
    string c;
    int l1,l2,l3,l4;
    in.open("/Users/daviddelval/Desktop/In.txt");
    int cas;
    in>>cas;
    for(int i=1;i<=cas;++i){
        aux.clear();
        aux2.clear();
        in>>l1>>l2>>l3>>l4;
        in>>v;
        in>>s1>>s2>>s3>>s4;
        aux=lc(s1,s2,v);
        for(string el:aux){
            if(s3.find(el)!=string::npos){
                aux2.push_back(el);
            }
        }
        for(string el:aux2){
            if(s4.find(el)!=string::npos){
                c=el;
            }
        }
        out<<"Case #"<<i<<":";
        out<<" "<<s1.find(c);
        out<<" "<<s2.find(c);
        out<<" "<<s3.find(c);
        out<<" "<<s4.find(c);
        out<<"\r\n";
    }
    return 0;
}

