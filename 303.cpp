//针对数组不变且存在频繁区间求和查询的场景，核心思路是利用**前缀和（Prefix Sum）**进行 ‭$O$‬‭$($‬‭$n$‬‭$)$‬ 预处理：构建一个前缀和数组 ‭$P$‬，其中 ‭$P$‬‭$[$‬‭$i$‬‭$]$‬ 存储原数组前 ‭$i$‬ 个元素的累加和，从而将每次区间 ‭$[$‬‭$left$‬‭$,\hphantom{}$‬ ‭$right$‬‭$]$‬ 的求和查询由 ‭$O$‬‭$($‬‭$n$‬‭$)$‬ 的遍历转化为 ‭$O$‬‭$($‬‭$1$‬‭$)$‬ 的差值计算：‭$P$‬‭$[$‬‭$right $‬‭$\hphantom{}+ 1$‬‭$] $‬‭$\hphantom{}- P$‬‭$[$‬‭$left$‬‭$]$‬

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n+1,0);

        for (int i=0; i<n; ++i){
            sum[i+1] = sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return (int) (sum[right+1] - sum[left]);
    }
};
