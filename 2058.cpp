//2058. 找出临界点之间的最小和最大距离

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // 临界点至少需要前中后三个节点，不足则直接返回
        if (!head || !head->next || !head->next->next) return {-1, -1};

        vector<int> criticalIdx;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int idx = 1; // 从第二个节点开始算起

        while (cur->next) {
            int v = cur->val;
            int p = prev->val;
            int n = cur->next->val;

            // 极大值点 或 极小值点
            if ((v > p && v > n) || (v < p && v < n)) {
                criticalIdx.push_back(idx);
            }
            prev = cur;
            cur = cur->next;
            idx++;
        }

        if (criticalIdx.size() < 2) return {-1, -1};

        int min_dist = INT_MAX;
        // 技巧：最大距离就是首尾之差
        int max_dist = criticalIdx.back() - criticalIdx.front();

        // 技巧：最小距离只在相邻点产生，O(n) 遍历
        for (int i = 1; i < criticalIdx.size(); ++i) {
            min_dist = min(min_dist, criticalIdx[i] - criticalIdx[i-1]);
        }

        return {min_dist, max_dist};
    }
};
