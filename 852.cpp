//符合山脉属性的数组 arr（长度至少为 3）满足其元素先从起始处单调递增至某个峰值下标 i，随后单调递减至末尾，请设计并实现一个时间复杂度为 ‭$O$‬‭$($‬‭$\log n$‬‭$)$‬ 的算法，找到并返回该峰值元素的下标 i。

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n - 1; ++i) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i;
            }
        }
        return 0;
    }
};
