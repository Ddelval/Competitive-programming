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
struct retvalue{
    int val;
    string still;
    retvalue(int a,string s){
        val=a;
        still=s;
    }
};
string input,output;
int aa[10];
int length;
int maxpunt;
int cost[26][26];
int equiv[10][4]={
    {-1,-1,-1},{-1,-1,-1,-1},
    {1,2,3,-1},{4,5,6,-1},{7,8,9,-1},{10,11,12,-1},{13,14,15,-1},
    {16,17,18,19},{20,21,22},{23,24,25,26}

};
retvalue evaluate(int pchar,int cursor,int pcost){
    int ncost;
    int a,b,c;
    string s;
    char x=' ';
    retvalue v(0,"");
    retvalue o(0,"");
    int maxim=-1;
    if(cursor==length){
        return retvalue(0,"");
    }
    
    for(int i=0;i<4;++i){
        if(equiv[aa[cursor]][i]==-1)break;
        a=aa[cursor];
        b=equiv[a][i];
        c=cost[pchar][b];
        ncost=pcost+c;
        v=evaluate(equiv[aa[cursor]][i],cursor+1,ncost);
        if(v.val>maxim){
            o=v;
            x=equiv[aa[cursor]][i]+'A'-1;
            maxim=v.val;
        }
    }
    s="";
    s+=x;
    return retvalue(o.val, o.still.insert(0, s));
}


typedef pair<int,int> ii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    ifstream in("/Users/daviddelval/Desktop/In.txt");
    ofstream out("/Users/daviddelval/Desktop/Out.txt");
    int cas;
    string s;
    int L,K;
    in>>cas;
    for(int i=1;i<=cas;++i){
        in>>L>>K;
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                in>>cost[i][j];
            }
        }
        in>>input;
        for(int i=0;i<input.length();++i){
            aa[i]=input[i]-'0';
        }
        char x=' ';
        retvalue v(0,"");
        retvalue o(0,"");
        length=input.length();
        int maxim=-1;
        for(int i=0;i<4;++i){
            if(equiv[aa[0]][i]==-1)break;
            v=evaluate(equiv[aa[0]][i],1,0);
            if(v.val>maxim){
                o=v;
                x=equiv[aa[0]][i]+'A'-1;
                maxim=v.val;
            }
        }
        s="";
        s+=x;
        string sol=v.still.insert(0, s);
        out<<sol;
        
        
    }
    
    
    
}
