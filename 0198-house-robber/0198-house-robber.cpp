class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101][2];
        memset(dp, 0, sizeof(dp));

        for(int i=1; i <= nums.size() ; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i-1];
        }

        return max(dp[nums.size()][0], dp[nums.size()][1]);
    }
};