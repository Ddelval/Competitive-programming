import java.math.BigInteger;
class Solution {
    BigInteger factorial(int n) {
		BigInteger b=BigInteger.ONE;
		for(int i=2;i<=n;++i) {
			b=b.multiply(BigInteger.valueOf(i));
		}
		return b;
	}
	public int uniquePaths(int m, int n) {
		m--;
		n--;
		BigInteger res= BigInteger.ONE;
		BigInteger a1,a2,a3;
        a1=factorial(n);
        a2=factorial(m);
        a3=factorial(m+n);
		res=res.multiply(a3);
		res=res.divide(a1);
		res=res.divide(a2);
		
		return res.intValue();
    }
}
