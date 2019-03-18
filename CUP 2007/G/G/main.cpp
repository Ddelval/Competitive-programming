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

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(int j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
char mat[17][17];
int main() {
    ios::sync_with_stdio(false);
    long len,length,rem,wid,hei;
    string input,out;
    cin>>len;
    getline(cin,input);
    while(len--){
        getline(cin,input);
        input=input.substr(0,input.length()-1);
        bool found=false;
        for(int i=1;i<=16;++i){
            length=input.length();
            rem=length%i;
            wid=length/i;
            if(rem||wid>16) continue;
            hei=i;
            for(int i=0;i<16;++i){
                for(int j=0;j<16;++j){
                    mat[i][j]=' ';
                }
            }
            for(int i=0;i<input.length();++i){
                mat[i%hei][i/hei]=input[i];
            }
            bool flag;
            bool invalid=false;
            for(int i=0;i<16;++i){
                flag=false;
                for(int j=0;j<16;++j){
                    if(flag&&mat[i][j]!=' '){
                        invalid = true;
                        break;
                    }
                    else if(mat[i][j]==' '||mat[i][j]=='.'||mat[i][j]==','||mat[i][j]==':'||mat[i][j]==';'){
                        flag=true;
                    }
                }
                if(invalid){
                    break;
                }
                
            }
            if(invalid){
                continue;
            }
            out="";
            //echo_tablero(wid, hei, mat);
            for(int i=0;i<16;++i){
                for(int j=0;j<16;++j){
                    if(mat[i][j]==' ') break;
                    else out+=(mat[i][j]);
                }
                out+=" ";
            }
            out=out.substr(0,out.length()-1);
            cout<<out<<"\n";
            found=true;
            break;
        }
        if(!found) cout<<"-- NO SOLUTION --\n";
    }
    return 0;
}

