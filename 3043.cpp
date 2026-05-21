//最长公共前缀的长度
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;
        for (int num : arr1) {
            string str = to_string(num);
            for (int i = 1; i <= str.size(); i++) {
                s.insert(str.substr(0, i));
            }
        }

        int maxLen = 0;
        for (int num : arr2) {
            string str = to_string(num);
            for (int i = 1; i <= str.size(); i++) {
                string pre = str.substr(0, i);
                if (s.count(pre)) {
                    maxLen = max(maxLen, i);
                } else {
                    break; 
                }
            }
        }

        return maxLen;
    }
};
