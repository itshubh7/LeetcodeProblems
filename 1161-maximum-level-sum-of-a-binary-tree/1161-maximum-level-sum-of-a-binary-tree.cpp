/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void solve(TreeNode* root, int level) {
        if (root == NULL)
            return;
        if (res[level] != INT_MIN)
            res[level] += root->val;
        else
            res[level] = root->val;

        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        res.resize(10001, INT_MIN);
        solve(root, 0);
        int maxSum = INT_MIN;
        int level = -1;
        for (int i = 0; i < res.size(); i++) {
            if (maxSum < res[i]) {
                maxSum = res[i];
                level = i + 1;
            }
        }

        return level;
    }
};