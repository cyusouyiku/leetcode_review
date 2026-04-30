//给你一个下标从 0 开始的数组 nums，数组中有 n 个整数，另给你一个整数 k。半径为k 的子数组平均值 是指：nums 中一个以下标 i 为中心且半径为 k 的子数组中所有元素的平均值。即下标在 ‭$[$‬‭$i $‬‭$\hphantom{}- k$‬‭$,\hphantom{}$‬ ‭$i $‬‭$\hphantom{}+ k$‬‭$]$‬ 范围（含 ‭$i $‬‭$\hphantom{}- k$‬ 和 ‭$i $‬‭$\hphantom{}+ k$‬）内所有元素的平均值。如果在下标 i 前或后不足 k 个元素，那么 半径为 k 的子数组平均值 是 -1。构建并返回一个长度为 n 的数组 avgs，其中 avgs[i] 是以下标 i 为中心的子数组的 半径为 k 的子数组平均值。$x$‬ 个元素的 平均值 是 ‭$x$‬ 个元素相加之和除以 ‭$x$‬，此时使用 截断式整数除法，即需要去掉结果的小数部分。•	例如，四个元素 2、3、1 和 5 的平均值是 ‭$($‬‭$2 $‬‭$\hphantom{}+ 3 $‬‭$\hphantom{}+ 1 $‬‭$\hphantom{}+ 5$‬‭$) $‬‭$\hphantom{}/ 4 $‬‭$\hphantom{}= 11 $‬‭$\hphantom{}/ 4 $‬‭$\hphantom{}= 2.75$‬，截断后得到 2。

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1); 
        long long windowSize = 2 * k + 1;

        if (n < windowSize) return avgs;

        // 1. 初始化第一个窗口的和
        long long currentWindowSum = 0;
        for (int i = 0; i < windowSize; ++i) {
            currentWindowSum += nums[i];
        }

        // 2. 开始滑动窗口
        for (int i = k; i <= n - k - 1; ++i) {
            avgs[i] = currentWindowSum / windowSize;
            
            // 移动窗口：减去左边滑出的，加上右边滑进的
            if (i + k + 1 < n) {
                currentWindowSum = currentWindowSum - nums[i - k] + nums[i + k + 1];
            }
        }

        return avgs;
    }
};
