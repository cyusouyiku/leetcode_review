//有效单词计数

#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string text;
        for (auto& part : chunks) {
            text += part;
        }

        unordered_map<string, int> freq;
        string current;
        int n = text.size();
        for (int i = 0; i < n; ++i) {
            char c = text[i];
            if (islower(c)) {
                current += c;
            } else if (c == '-' && !current.empty() && i + 1 < n && islower(text[i+1])) {
                current += c;
            } else {
                if (!current.empty()) {
                    freq[current]++;
                    current.clear();
                }
            }
        }
        if (!current.empty()) {
            freq[current]++;
        }

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(freq[q]);
        }
        return ans;
    }
};
