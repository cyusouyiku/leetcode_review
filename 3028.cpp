//3028:边界上的蚂蚁

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0;
        int currentPos = 0; // 必须在循环外，记录累积位置
        
        for(int i = 0; i < nums.size(); ++i) {
            currentPos += nums[i]; // 直接累加，正代表向右，负代表向左
            
            if(currentPos == 0) {
                ans++; // 只有当累积位置回到 0 时，才算回到边界
            }
        }
        return ans;
    }
};
