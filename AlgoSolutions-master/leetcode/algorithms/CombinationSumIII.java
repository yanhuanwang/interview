/*
 * Find all possible combinations of k numbers that add up to a number 
 * n, given that only numbers from 1 to 9 can be used and each 
 * combination should be a unique set of numbers.
 * 
 * Ensure that numbers within the set are sorted in ascending order.
 * 
 * Example 1:
 * 
 * Input: k = 3, n = 7
 * 
 * Output:
 * 
 * [[1,2,4]]
 * 
 * Example 2:
 * 
 * Input: k = 3, n = 9
 * 
 * Output:
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 */
public class CombinationSumIII {

    public List<List<Integer>> combinationSum3(int k, int n) {
        return dfs(k, n, 1);
    }

    public List<List<Integer>> dfs(int k, int n, int start) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (k == 1 && start <= n && n <= 9) {
            List<Integer> list = new ArrayList<Integer>();
            list.add(n);
            result.add(list);
            return result;
        }
        for (int i = start; i <= n; i++) {
            for (List<Integer> list : dfs(k - 1, n - i, i + 1)) {
                list.add(0, i);
                result.add(list);
            }
        }
        return result;
    }

}
