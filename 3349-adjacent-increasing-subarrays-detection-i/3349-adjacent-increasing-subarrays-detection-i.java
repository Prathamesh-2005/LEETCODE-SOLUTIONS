class Solution {
    public boolean check(int start, List<Integer> nums, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums.get(i) >= nums.get(i + 1)) {
                return false;
            }
        }
        return true;
    }

    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();

        for (int i = 0; i + 2 * k <= n; i++) {
            boolean first = check(i, nums, k);
            boolean second = check(i + k, nums, k);

            if (first && second) {
                return true;
            }
        }

        return false;
    }
}
