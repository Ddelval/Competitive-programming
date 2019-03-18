#include <iostream>
#include <vector>
using namespace std;
long euclides_extendido(long  a,  long b)
{
    long arr1,arr2;
    long long x1, x2, y1, y2;
    long long q, r;
    
    // Base case
    x2 = 1; x1 = 0;
    y2 = 0; y1 = 1;
    
    //Recursive procedure
    //Refer to http://esfm.egormaximenko.com/linalg/gcd_extended_es.pdf page 2
    while (b > 0) {
        q= a / b;
        r= a - q * b;
        
        arr1= x2 - q * x1;
        arr2= y2 - q * y1;
        
        a= b;
        b= r;
        
        x2= x1;
        y2= y1;
        
        x1= arr1;
        y1= arr2;
    }
    
    return y2;
}
long long OperacionZn(long long a, long long n)
{
    long inv;
    inv = euclides_extendido(n, a);
    if (inv < 0){
            return inv + n;
    }
    else{
            return inv;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    double n,k;
    long long factor;
    long long sum=1;
    while(cin>>n>>k&&(n||k)){
        sum=1;
        cout<<"1 ";
        for(int i=0;i<k-1;i++){
            factor=(n-i)*OperacionZn(i+1,1000000007);
            factor%=1000000007;
            sum*=factor;
            sum%=1000000007;
            cout<<sum<<" ";
            }
        factor=(n-(k-1))*OperacionZn(k,1000000007);
        factor%=1000000007;
        sum*=factor;
        sum%=1000000007;
        cout<<sum<<"\n";
    }
}
