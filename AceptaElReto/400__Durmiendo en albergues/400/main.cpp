// AceptaElReto 400:  Durmiendo en albergues
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int start,end;
    int i;
    int out;
    int ma,counter;
    while(getline(cin, s)){
        ma=counter=0;
        start=end=0;
        for(i=0;i<s.length();i++){
            if(s[i]=='X'){
                break;
            }
            start++;
        }
        for(i++;i<s.length();i++){
            if(s[i]=='.'){
                counter++;
            }
            else{
                if(counter){
                    if(counter>ma){
                        
                        ma=counter;
                    }
                    counter=0;
                }
            }
        }
        if(counter){
            end=counter;
        }
        if(!(ma%2)){
            out=(ma-1)/2;
        }
        else{
          out=ma/2;
        }
        start--;end--;
        cout<<max(max(out,end),start)<<"\n";
    }
    return 0;
}

