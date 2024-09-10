/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
        return {};
   queue<TreeNode*>q;
   q.push(root);
   vector<int>ans;
   
   while(!q.empty())
   {
       ans.push_back(q.back()->val);
       
       int n = q.size();
       while(n--)
       {
           TreeNode* temp = q.front();
           q.pop();
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
           
       }
   }
   return ans;
        
    }
};