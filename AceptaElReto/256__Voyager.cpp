// AceptaElReto 256:  Voyager

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

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    string s1,s2,s3,out;
    bool noise,flag;
    int length;
    while(cin>>s1>>s2>>s3){
        length=(int)max(s1.length(),s2.length());
        length=(int)max(length,(int)s3.length());
        for(int i=(int)s1.length();i<length;++i){
            s1.insert(0,"0");
        }
        for(int i=(int)s2.length();i<length;++i){
            s2.insert(0,"0");
        }
        for(int i=(int)s3.length();i<length;++i){
            s3.insert(0,"0");
        }
        out="";
        noise=false;
        for(int i=0;i<length;++i){
            if(s1[i]==s2[i]){
                out+=s1[i];
            }
            else if(s1[i]==s3[i]){
                out+=s1[i];
            }
            else if(s3[i]==s2[i]){
                out+=s2[i];
            }
            else{
                noise=true;
                break;
            }
        }
        
        if(noise) cout<<"RUIDO COSMICO\n";
        else{
            flag=true;
            int i;
            for(i=0;i<length;++i){
                if(out[i]!='0'){
                    cout<<out[i];
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"0\n";
            else{
                for(;i<length;++i)cout<<out[i];
                cout<<"\n";
            }
            
        }
    }
    
    return 0;
}
