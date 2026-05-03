//872. 叶子相似的树

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        return leaves1 == leaves2; 
    }

    void getLeaves(TreeNode* root, vector<int>& res) {
        if (!root) return;
        
        // 判断是否为叶子节点：左右都为空
        if (!root->left && !root->right) {
            res.push_back(root->val);
        }
        
        // 递归去左边找，再去右边找
        getLeaves(root->left, res);
        getLeaves(root->right, res);
    }
};
