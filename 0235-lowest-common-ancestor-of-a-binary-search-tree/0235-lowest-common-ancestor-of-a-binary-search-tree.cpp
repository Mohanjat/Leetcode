/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;
        
        if(root == p) return p;
        if(root == q) return q;
        
        //left se answer lekr aao 
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        //right se answer lekr aao
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        
        if(left == NULL && right == NULL){
            return NULL;
        }
        else if(left == NULL && right != NULL){
            return right;
        }
        else if(left != NULL && right == NULL){
            return left;
        }
        else{
            return root;
        }
        
    }
};