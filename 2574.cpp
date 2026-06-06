class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = abs(leftSum(nums, i) - rightSum(nums, i));
        }

        return ans;
    }

    int leftSum(vector<int>& nums, int curr) {
        int sum = 0;

        for (int i = 0; i < curr; ++i) {
            sum += nums[i];
        }

        return sum;
    }

    int rightSum(vector<int>& nums, int curr) {
        int sum = 0;

        for (int j = nums.size() - 1; j > curr; --j) {
            sum += nums[j];
        }

        return sum;
    }
};
