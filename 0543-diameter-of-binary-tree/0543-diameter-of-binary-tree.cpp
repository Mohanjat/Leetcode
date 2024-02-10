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
    
    int height(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left,right)+1;
    }
    
    int diameter(TreeNode* root){
        //base case
        if(root == NULL) return 0;
        
        //yaa to answer left subtree se aayega
        int a = diameter(root->left);
        //yaa phir right subtree se aayega
        int b = diameter(root->right);
        //yaa phir root se hote huye aayega
        int c = height(root->left) + height(root->right) + 1;
        
        return max(a,max(b,c));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameter(root) -1;
         
    }
};