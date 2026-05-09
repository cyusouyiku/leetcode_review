//3759统计合格元素的数目

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            return n;
        }
        ranges::sort(nums);
        return ranges::lower_bound(nums, nums[n - k]) - nums.begin(); // 小于第 k 大的元素个数
    }
};

