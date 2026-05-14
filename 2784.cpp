class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        // 长度必须是 n+1
        if (nums.size() != n + 1) {
            return false;
        }
        // 统计每个数字出现次数
        vector<int> cnt(n + 1, 0);
        for (int x : nums) {
            // 超出范围的数字直接无效
            if (x < 1 || x > n) {
                return false;
            }
            cnt[x]++;
        }
        // 检查 1~n-1 各出现1次，n出现2次
        for (int i = 1; i < n; i++) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        return cnt[n] == 2;
    }
};
