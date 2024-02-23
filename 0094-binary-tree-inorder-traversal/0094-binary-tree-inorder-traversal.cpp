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
    
    void inOrder(TreeNode* root, vector<int> &ans){
        //base case
        if(root == NULL){
            return;
        }
        
        inOrder(root->left,ans);
        //now store the node data;
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        //this is inorder traversal // left node print and then going to right
        
        //LNR
        
        //Morris Traversal
        
        vector<int> ans;
        
        TreeNode* curr = root;
        
        while(curr){
            //left node is NULL, then visit it and go right
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                //left node is not NULL
                
                //1- predecessor nikal lo
                TreeNode* pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }
                
                //yha se niklne ke baad we having two condition
                //if pred right node is NULL go left after establishing link from pred to curr
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    //left is already visited,break the link of pred and
                    //go right after visiting curr node
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};