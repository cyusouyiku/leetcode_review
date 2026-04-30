//在数组中找出所有长度为 ‭$k$‬ 且元素总和大于等于 ‭$($‬‭$k $‬‭$\hphantom{}\times \text{threshold}$‬‭$)$‬ 的连续子数组的个数。

//暴力模拟，我想出来的如下
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;

        int n = arr.size();

        for (int i= k-1; i<n;++i){
            if (total_sum(arr,i-k+1,i)/k >= threshold){
                count += 1;
            }
        }

        return count;
        
    }

    int total_sum(vector<int>& arr, int left, int right){
        int sum = 0;
        for (int i=left;i<=right;++i){
            sum+=arr[i];
        }

        return sum;
    }

};



//滑动窗口
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int n = arr.size();
        
        // 目标：总和只要大于等于 target 即可
        long long target = (long long)k * threshold;
        long long current_sum = 0;

        // 1. 先计算第一个窗口（前 k 个元素）的和
        for (int i = 0; i < k; ++i) {
            current_sum += arr[i];
        }

        // 2. 检查第一个窗口
        if (current_sum >= target) {
            count++;
        }

        // 3. 开始滑动窗口
        for (int i = k; i < n; ++i) {
            // 加上新进入窗口的元素 arr[i]
            // 减去离开窗口的元素 arr[i - k]
            current_sum += arr[i] - arr[i - k];
            
            if (current_sum >= target) {
                count++;
            }
        }

        return count;
    }
};
