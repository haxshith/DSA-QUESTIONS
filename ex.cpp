class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        vector<int> dp(n, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;        
        if (n == 1) return nums[0];   

        int case1 = robLinear(nums, 0, n - 2);

        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
