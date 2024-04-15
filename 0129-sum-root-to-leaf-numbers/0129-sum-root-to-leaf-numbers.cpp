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
    
    void solve(TreeNode* root, long long temp,long long &ans){
        if(root == NULL){
            return;   
        }
        
        if(root->left == NULL && root->right == NULL){
            temp = temp*10+root->val;
            ans += temp;
        }
        
        solve(root->left,temp*10+root->val,ans);
        
        solve(root->right,temp*10+root->val,ans);
        
    }
    
    long long sumNumbers(TreeNode* root) {
        
        long long ans = 0;
        
        solve(root,0,ans);
        
        return ans;
        
    }
};