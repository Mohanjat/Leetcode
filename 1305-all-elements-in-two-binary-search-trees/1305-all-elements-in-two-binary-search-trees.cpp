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
    
    void inorderTraversal(TreeNode* root,vector<int>& inorder){
        
        if(root == NULL) return;
        
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> inorder1;
        vector<int> inorder2;
        
        inorderTraversal(root1,inorder1);
        inorderTraversal(root2,inorder2);
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        
        while(i<inorder1.size() && j<inorder2.size()){
            if(inorder1[i] < inorder2[j]){
                ans.push_back(inorder1[i]);
                i++;
            }else{
                ans.push_back(inorder2[j]);
                j++;
            }
        }
        
        while(i<inorder1.size()){
             ans.push_back(inorder1[i]);
             i++;  
        }
        
        while(j<inorder2.size()){
            ans.push_back(inorder2[j]);
            j++;
        }
        return ans;
    }
};