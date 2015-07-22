/*
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return 
 * the bitwise AND of all numbers in this range, inclusive.

 * For example, given the range [5, 7], you should return 4.
 */
public class BitwiseANDOfNumbersRange {

    public int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << 31 - i;
            if ((m & n & mask) != 0 && (n - m) <= mask)
                result += mask;
        }
        return result;
    }

}
