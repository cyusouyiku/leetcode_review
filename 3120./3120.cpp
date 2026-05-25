//统计特殊字母的数量，特殊字母就是在vector中大小写至少都出现一次
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.count(c) && s.count(c - 'a' + 'A')) {
                ans++;
            }
        }
        return ans;
    }
};
