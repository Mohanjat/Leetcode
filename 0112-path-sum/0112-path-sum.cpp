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
    
    bool solve(TreeNode* root, int targetSum){
        
        if(root == NULL) return false;
        
        if((root->left == NULL) && (root->right == NULL)){
            if(targetSum - root->val == 0) return true;
        }
        
        // if(targetSum < 0) return false;
        
        //left m jao
        bool l = solve(root->left,targetSum-root->val);
        //right m jao
        bool r = solve(root->right,targetSum-root->val);
        
        return l|r;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // if(root == NULL || targetSum == 0){
        //     return false;
        // }
        
        return solve(root,targetSum);
        
    }
};