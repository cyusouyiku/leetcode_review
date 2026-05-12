//3927.替换成最小的因子
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        // 1. 找到最大值，建立布尔桶
        int max_val = 0;
        for (int x : nums) if (x > max_val) max_val = x;
        
        vector<bool> exists(max_val + 1, false);
        for (int x : nums) exists[x] = true;

        long long totalSum = 0;

        // 2. 预处理：每个数能变成的最小值
        // 我们用一个数组记录从 1 到 max_val，每个数如果存在于 nums，它能转化的最小目标
        vector<int> min_target(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            if (!exists[i]) continue;
            
            // 如果 i 存在，我们需要找到它的最小因子 j，且 exists[j] 为 true
            // 技巧：从小到大枚举因子
            int best = i;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    if (exists[j]) {
                        best = j; 
                        break; // 1 是最小的，如果 exists[1] 为真，直接就是 1
                    }
                    // 检查对称因子 i/j
                    if (exists[i / j]) {
                        // 注意：i/j 比较大，所以我们要等循环完看有没有更小的
                        best = min(best, i / j);
                    }
                }
            }
            min_target[i] = best;
        }

        // 3. 累加结果
        for (int x : nums) {
            totalSum += min_target[x];
        }

        return totalSum;
    }
};



//灵神优化算法如下：其实就是把每个数的因子先从小到大放出来，然后再一个一个遍历，其实就是空间换时间，空间就是每个因子。
constexpr int MX = 100'001;
vector<int> divisors[MX];

int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) { // 枚举 i 的倍数 j
            divisors[j].push_back(i); // i 是 j 的因子
        }
    }
    return 0;
}();

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }

        long long ans = 0;
        for (auto& [x, c] : cnt) { // 遍历 cnt 而不是 nums，这样重复元素只会计算一次
            for (int d : divisors[x]) { // 从小到大枚举 x 的因子 d
                if (cnt.contains(d)) {
                    ans += 1LL * d * c; // 把 x 变成 d 是最优的
                    break;
                }
            }
        }
        return ans;
    }
};












