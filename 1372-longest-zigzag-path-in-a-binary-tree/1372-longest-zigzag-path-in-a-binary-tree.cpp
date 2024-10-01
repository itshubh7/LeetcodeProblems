class Solution {
public:
    unordered_map<TreeNode*,array<int,2>> mp;
    int ans=0;
    void help(TreeNode*root){
        if(root==nullptr) return ;
        mp[root][0]=mp[root][1]=0;
        help(root->right);
        help(root->left);
        if(root->left==nullptr && root->right==nullptr){
            mp[root][0]=mp[root][1]=1;
        }
        else{
            if(root->right!=nullptr){
                mp[root][1]=1+mp[root->right][0];
            }else mp[root][1]=1;
            if(root->left!=nullptr){
                mp[root][0]=1+mp[root->left][1];
            }else mp[root][0]=1;
        }
        ans=max(ans,max(mp[root][0],mp[root][1]));
      
    }
    int longestZigZag(TreeNode* root) {
        
        help(root);
        return ans-1;

    
    }
};