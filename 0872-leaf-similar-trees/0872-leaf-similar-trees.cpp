class Solution {
public:
    void Traverse(TreeNode* root,vector<int> &v){
        if(root == NULL){
            return;
        }
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        Traverse(root->left,v);
        
        Traverse(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2;
        Traverse(root1,r1);
        Traverse(root2,r2);
        return r1 == r2;
        
    }
};