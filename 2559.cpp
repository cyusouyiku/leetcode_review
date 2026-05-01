//要求根据给定的字符串数组 words 和查询数组 queries，计算每个查询范围 ‭$[$‬‭$l_i$‬‭$,\hphantom{}$‬ ‭$r_i$‬‭$]$‬ 内满足以元音字母开头且结尾的字符串数量，并返回结果数组。解决该题的高效策略是使用 前缀和（Prefix Sum） 技术：先预处理出一个前缀和数组，记录到当前位置为止符合条件的字符串总数，从而将每个区间查询的时间复杂度从 ‭$O$‬‭$($‬‭$n$‬‭$)$‬ 降低至 ‭$O$‬‭$($‬‭$1$‬‭$)$‬。


//我的solution，有bug
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < queries[i].size(); j += 2) {
                int start = queries[i][0];
                int end = queries[i][1];
                ans.push_back(count_ans(words, 0, end) - count_ans(words, 0, start - 1));
            }
        }
        return ans;
    }

    int count_ans(vector<string>& words, int start, int end) {
        if (end < 0) return 0;
        int count = 0;
        for (int i = start; i <= end; ++i) {
            string s = words[i];
            for (char a : s) {
                if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
                    count += 1;
                }
            }
        }
        return count;
    }
};



//答案
class Solution {
public:
    // 辅助函数：判断首尾是否都是元音
    bool isVowelString(const string& s) {
        if (s.empty()) return false;
        auto check = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        return check(s.front()) && check(s.back());
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        // 1. 预处理：构建前缀和数组 P
        // P[i+1] 表示从 words[0] 到 words[i] 中满足条件的字符串总数
        vector<int> P(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            P[i + 1] = P[i] + (isVowelString(words[i]) ? 1 : 0);
        }

        // 2. 瞬间查询
        vector<int> ans;
        for (const auto& q : queries) {
            int left = q[0], right = q[1];
            // 直接 O(1) 算出区间和
            ans.push_back(P[right + 1] - P[left]);
        }
        return ans;
    }
};
