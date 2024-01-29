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
    
     bool checkSymmetry(TreeNode* p, TreeNode* q) {
        
        if(p == NULL && q == NULL){
            return true;
        }
        
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        
        if(p->val != q->val){
            return false;
        }
        
        bool check1 =  checkSymmetry(p->left,q->right);
        bool check2 = checkSymmetry(p->right,q->left);
    
        
        return check1&check2;
     }
    
    bool isSymmetric(TreeNode* root) {
        
        TreeNode* root1 = root;
        TreeNode* root2 = root;
        
        return checkSymmetry(root1,root2);
        
    }
};