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
    
    void inorderTraversal(TreeNode* root,vector<int> &v){
        if(!root) return;
        
        inorderTraversal(root->left,v);
        v.push_back(root->val);
        inorderTraversal(root->right,v);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> inorder;
        
        inorderTraversal(root,inorder);
        
        int mini = INT_MAX;
        
        for(int i=0; i<inorder.size()-1; i++){
            int diff = (inorder[i+1]-inorder[i]);
            mini = min(mini,diff);
        }
        return mini;
    }
};