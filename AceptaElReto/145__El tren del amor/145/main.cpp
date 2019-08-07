#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    stack<char> s;
    string a;
    int counter;
    while(getline(cin,a)){
        while(!s.empty()){
            s.pop();
        }
        counter=0;
        for(int i=0;i<a.length();i++){
            switch (a[i]) {
                case 'H':
                    s.push('H');
                    break;
                case 'h':
                    s.push('h');
                    break;
                case 'M':
                    if(!s.empty()&&s.top()=='H'){
                        s.pop();
                        counter++;
                    }
                    else{
                        while(!s.empty()){
                            s.pop();
                        }
                    }
                    break;
                case 'm':
                    if(!s.empty()&&s.top()=='h'){
                        s.pop();
                        counter++;
                    }
                    else{
                        while(!s.empty()){
                            s.pop();
                        }
                    }
                    break;
                case '@':
                    while(!s.empty()){
                        s.pop();
                    }
                    break;
                default:
                    break;
            }
            
        }
        cout<<counter<<"\n";
    }
    return 0;
}
