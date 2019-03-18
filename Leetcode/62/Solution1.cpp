class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        long long a=1;
        int b;
        if(m<n){
            b=m;
            m=n;
            n=b;
        }
        for(int i=1;i<=n;++i){
            a*=(m+n)-(i-1);
            a/=i;
        }
        return a;
    }
};