class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        return traverseNode(root, targetSum);
    }
    int traverseNode(TreeNode* root, int target) {
        if (root == nullptr) {
            return 0;
        }
        return traversePath(root, 0, target) + traverseNode(root->left, target) + traverseNode(root->right, target);
    }

    int traversePath(TreeNode* root, long currentSum, int target) {
        if (root == nullptr) {
            return 0;
        }
        currentSum += root->val;
        int left = traversePath(root->left, currentSum, target);
        int right = traversePath(root->right, currentSum, target);
        int res = left+right;
        return currentSum==target ? res+1 : res;
    }
};