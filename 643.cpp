//给定一个整数数组 nums 和一个整数 k，请在所有长度固定为 k 的连续子数组中，找到并返回那个最大的平均值。

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = std::accumulate(nums.begin(), nums.begin() + k, 0.0);
        double max_sum = sum;

        //就看滑进来的和滑出去的差
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, sum);
        }

        return max_sum / k;
    }
};
