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
    
    TreeNode* solve(TreeNode* root,int target){
        
        if(root == NULL) return NULL;
        
        if(root->left == NULL && root->right == NULL){
            if(root->val == target){
                // cout<<"target value is "<<root->val<<endl;
                return NULL;
            }
            //means it's a leaf node and equal to target need to delete this node
            return root;
        }
        
    
        //left se answer nikaalo
        TreeNode* l = removeLeafNodes(root->left,target);
        //and right se answer nikaalo
        TreeNode* r = removeLeafNodes(root->right,target);
        
        if(l == NULL && root->left != NULL) root->left = NULL;
        if(r == NULL && root->right != NULL) root->right = NULL;
        
        if(root->left == NULL && root->right == NULL && root->val == target){
            // cout<<"target value is "<<root->val<<endl;
            return NULL;
        }
        else{
            return root;
        }
        
    }
    
    void print(TreeNode* root){
        if(!root) return;
        cout<<"root val "<<root->val<<endl;
        print(root->left);
        print(root->right);
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* ans = solve(root,target);
        
        // print(ans);
        return ans;
    }
};