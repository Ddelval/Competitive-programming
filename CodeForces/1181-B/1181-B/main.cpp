//
//  main.cpp
//  1181-B
//
//  Created by David del Val on 16/06/2019.
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
#include <string.h>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

string sum(string s1,string s2){
    string res;
    int lim=(int)max(s1.length(),s2.length());
    res.reserve(lim+1);
    int pos1,pos2;
    int carry=0;
    int tmp;
    for(int i=0;i<lim;++i){
        pos1=(int)s1.length()-i-1;
        pos2=(int)s2.length()-i-1;
        if(pos1<0){
            if(pos2<0){
                res+='0';
            }
            else{
                tmp=s2[pos2]-'0'+carry;
                if(tmp>9){
                    carry=1;
                    tmp%=10;
                }
                else{
                    carry=0;
                }
                res+=tmp+'0';
            }
            
        }
        else if(pos2<0){
            tmp=s1[pos1]-'0'+carry;
            if(tmp>9){
                carry=1;
                tmp%=10;
            }
            else{
                carry=0;
            }
            res+=tmp+'0';
        }
        else{
            tmp=s2[pos2]+s1[pos1]-'0'-'0'+carry;
            if(tmp>9){
                carry=1;
                tmp%=10;
            }
            else{
                carry=0;
            }
            res+=tmp+'0';
        }
    }
    if(carry)res+='1';
    string fin;
    for(int i=(int)res.length()-1;i>=0;--i){
        fin+=res[i];
    }
    return fin;
    
    
    
    
}
bool lesso(string s1,string s2){
    if(s1=="0")return false;
    if(s2=="0")return true;
    if(s1.length()>s2.length()) return false;
    if(s1.length()<s2.length()) return true;
    for(int i=0;i<s1.length();++i){
        if(s1[i]==s2[i]){
            continue;
        }
        if(s1[i]-s2[i]>0){
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    int len;
    string in;
    string op1;
    string op2;
    bool b;
    while(cin>>len){
        cin>>in;
        if(len%2==0){
            op1=in.substr(0,len/2);
            op2=in.substr(len/2,len/2);
            string sum1="0",sum2="0";
            if(op2[0]=='0'){
                //Find two options
                int i;
                for(i=len/2;i<in.length();++i){
                    if(in[i]!='0')break;
                }
                if(i!=in.length()){
                    op1=in.substr(0,i);
                    op2=in.substr(i,in.length()-i);
                    sum1=sum(op1,op2);
                }
                for(i=len/2;i>=0;--i){
                    if(in[i]!='0')break;
                }
                if(i!=0){
                    op1=in.substr(0,i);
                    op2=in.substr(i,in.length()-i);
                    sum2=sum(op1,op2);
                }
                if(lesso(sum1,sum2)){
                    cout<<sum1;
                }
                else{
                    cout<<sum2;
                }
            }
            else{
                cout<<sum(op1,op2);
            }
        }
        else{
            string m1,m2;
            op1=in.substr(0,len/2);
            op2=in.substr(len/2,len-len/2);
            string sum1="0",sum2="0";
            b=true;
            if(op2[0]=='0'){
                b=false;
                //Find two options
                int i;
                for(i=len/2;i<in.length();++i){
                    if(in[i]!='0')break;
                }
                if(i!=in.length()){
                    op1=in.substr(0,i);
                    op2=in.substr(i,in.length()-i);
                    sum1=sum(op1,op2);
                }
                for(i=len/2;i>=0;--i){
                    if(in[i]!='0')break;
                }
                if(i!=0){
                    op1=in.substr(0,i);
                    op2=in.substr(i,in.length()-i);
                    sum2=sum(op1,op2);
                }
                if(lesso(sum1,sum2)){
                    m1=sum1;
                }
                else{
                    m1=sum2;
                }
            }
            else{
                m1=sum(op1,op2);
            }
            op1=in.substr(0,len/2+1);
            op2=in.substr(len/2+1,len-len/2-1);
            sum1="0";
            sum2="0";
            if(op2[0]=='0'){
                //Find two options
                int i;
                for(i=len/2;i<in.length();++i){
                    if(in[i]!='0')break;
                }
                if(i!=in.length()){
                    op1=in.substr(0,i);
                    op2=in.substr(i,in.length()-i);
                    sum1=sum(op1,op2);
                }
                for(i=len/2;i>=0;--i){
                    if(in[i]!='0')break;
                }
                if(i!=0){
                    op1=in.substr(0,i);
                    op2=in.substr(i,in.length()-i);
                    sum2=sum(op1,op2);
                }
                if(lesso(sum1,sum2)){
                    m2=sum1;
                }
                else{
                    m2=sum2;
                }
            }
            else{
                m2=sum(op1,op2);
            }
            if(lesso(m1, m2)){
                cout<<m1;
            }
            else{
                cout<<m2;
            }
        }
        
        
        
        
        
    }
    return 0;
}
