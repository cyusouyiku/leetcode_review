//给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string str) {
        string res = "";
        for (char ch : str) {
            if (ch != '#') {
                res.push_back(ch);
            } else if (!res.empty()) {
                res.pop_back();   
            }
        }
        return res;
    }
};
