//在长度为 ‭$k$‬ 的滑动窗口内，维护一个哈希表来保证不同元素个数 ‭$\ge m$‬，并求出这些达标窗口的最大元素和。

//我最初的写法
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int count = 0;
        long long ans = 0;
        vector<int> temp = (k,-1);
        for (int i=0; i<k;i++){
            temp.push_back(nums[i]);
        }

        long long max = 0;

        for (int j=k;j<n;++j){
            if (is_true(nums,j-k,j,m)){
                ans = cal(nums,j-k,j) + nums[j]-nums[j-k];
                max = max(max,ans);
            }
        }

        return max;
    }

    bool is_true(vector<int> nums, int left, int right, int m){
        unordered_map<int, int> fre;
        for (int i=left;i<=right;++i){
            fre[i]++;
        }
        return fre.size() >= m;
    }

    int cal(vector<int> nums, int left, int right){
        int sum = 0;
        for (int i=left;i<=right;++i){
            sum += nums[i];
        }
        return sum;
    }
};



//正确答案
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int, int> counts; // 统计窗口内每个数字出现的次数
        long long currentSum = 0;
        long long maxResult = 0;

        // 1. 蓄水池阶段：初始化第一个长度为 k 的窗口
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
            counts[nums[i]]++;
        }

        // 检查第一个窗口是否满足“至少有 m 个互不相同的元素”
        if (counts.size() >= m) {
            maxResult = currentSum;
        }

        // 2. 入出水阶段：从下标 k 开始滑动
        for (int i = k; i < n; ++i) {
            // --- 出水：处理左边界 (i - k) ---
            int outNum = nums[i - k];
            currentSum -= outNum;
            counts[outNum]--;
            if (counts[outNum] == 0) {
                counts.erase(outNum); // 核心：计数归零必须删掉 key，否则 size() 不变
            }

            // --- 入水：处理右边界 (i) ---
            int inNum = nums[i];
            currentSum += inNum;
            counts[inNum]++;

            // --- 判优：每滑一步判断一次 ---
            if (counts.size() >= m) {
                maxResult = max(maxResult, currentSum);
            }
        }

        return maxResult;
    }
};
