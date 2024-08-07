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
    
    void rightView(TreeNode* root, int level, vector<int> &ans){
        //base case 
        if(root == NULL) return;
        
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        
        rightView(root->right,level+1,ans);
        rightView(root->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        int level = 0;
        vector<int> ans;
        
        rightView(root,level,ans);
        
        return ans;
        
    }
};