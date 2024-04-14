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
    
    int ans = 0;
    
    int solve(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
             ans += root->left->val;
        }
        
        int l = solve(root->left);
        
        int r = solve(root->right);
        
        return ans; 
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        return solve(root);
        
    }
};