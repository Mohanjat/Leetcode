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
    
    TreeNode* createTree(TreeNode* root,vector<int>&nums,int s, int e){
        
        if(s>e){
            return NULL;
        }
        
        //find mid element
        int mid = s + (e-s)/2;
        
        //create node using mid element
        root = new TreeNode(nums[mid]); 
        
        //add data into left part
        root->left = createTree(root,nums,s,mid-1);
        //add data into right part
        root->right = createTree(root,nums,mid+1,e);
        
        return root;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* root = new TreeNode();
        
        return createTree(root,nums,0,nums.size()-1);
        
    }
};