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
    
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        
        //base case 
        if(root == NULL) return NULL;
        
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;
        
        //lets traverse right and left part
        TreeNode* left = solve(root->left,p,q);
        TreeNode* right = solve(root->right,p,q);
        
        if(left == NULL && right == NULL){
            return NULL;
        }
        else if(left == NULL && right != NULL){
            return right;
        }else if(left != NULL && right == NULL){
            return left;
        }
        //agr dono trf se hi non null value h to mtlb wo root node hi answer h 
        // if(left != NULL && right != NULL){
        //     return root;
        // }       
        return root;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Approach -- first of all reach out p and q
        //here our biggest reason is the what should we return after reaching p and q
        //so we return the itself p and q
        //and if a node received non null values from both left and rigth sides 
        //then we can call this is out answer
        
        TreeNode* ans = solve(root,p,q);
        
        return ans;
    }
};