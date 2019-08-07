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
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    bool flag;
    stack<char> sta;
    string s;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        if(!s.length()){
            cout<<"Yes\n";
            continue;
        }
        flag=true;
        while(!sta.empty()) sta.pop();
        for(char c:s){
            if(c=='('||c=='[') sta.push(c);
            else if(c==')'){
                if(!sta.empty()&&sta.top()=='('){
                    sta.pop();
                }
                else{
                    flag=false;
                    break;
                }
            }
            else{
                if(!sta.empty()&&sta.top()=='['){
                    sta.pop();
                }
                else{
                    flag=false;
                    break;
                }
            }
        }
        if(!sta.empty()) flag=false;
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

