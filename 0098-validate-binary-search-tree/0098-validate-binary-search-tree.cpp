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
    
    bool isBST(TreeNode* root, long long minVal,long long maxVal){
        if(root == NULL) return true;
        
        if(root->val <= minVal || root->val >= maxVal) return false;
        
        return isBST(root->left,minVal,root->val) && isBST(root->right,root->val,maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;
       return isBST(root,LONG_MIN, LONG_MAX);
    }
};