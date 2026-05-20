//找到两个数组的公共前缀

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        // 这里的 i 代表当前遍历到的前缀截止下标
        for(int i = 0; i < A.size(); i++){
            int curr = count(A, B, i);
            ans.push_back(curr);
        }
        return ans;
    }

    // 顺着你的写法，传入当前前缀的截止下标 pfx_len
    int count(vector<int>& A, vector<int>& B, int pfx_len){
        unordered_map<int, int> fre_A;
        int counter = 0;

        // 1. 只把 A 中 0 到 pfx_len 的元素存入哈希表
        for (int i = 0; i <= pfx_len; ++i){
            fre_A[A[i]]++;
        }

        // 2. 同样只遍历 B 中 0 到 pfx_len 的元素
        for (int j = 0; j <= pfx_len; ++j){
            // 正确的语法：利用 .count() 检查 B[j] 是否在哈希表中
            if (fre_A.count(B[j])) {
                counter++;
            }
        }

        return counter;
    }
};
