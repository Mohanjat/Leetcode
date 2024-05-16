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
    bool evaluateTree(TreeNode* root){
        
        //base case - return the leaf node
        if(root->left == NULL && root->right == NULL){
            if(root->val == 1) 
                return true;
            else
                return false;
        }
        
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        
        int val = root->val;
        
        if(val == 2){
            return l|r;
        }
        else{
            return l&r;
        }
        
    }
};