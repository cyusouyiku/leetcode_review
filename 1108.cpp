//1108：使IP地址无效，就是把.都换成[.]

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;

        for (char a:address){
            if (a == '.'){
                ans += "[.]";
            }else{
                ans += a;
            }
        }
        return ans;
    }
};
