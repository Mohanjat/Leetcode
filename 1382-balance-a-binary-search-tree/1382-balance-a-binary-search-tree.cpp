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
    
    void inOrderTraversal(TreeNode* root,vector<int> &v){
        if(root == NULL) return;
        
        inOrderTraversal(root->left,v);
        v.push_back(root->val);
        inOrderTraversal(root->right,v);
    }
    
    TreeNode* BST_balanced(vector<int> &inorder,int s, int e){
        
        if(s>e) return NULL;
        
        int mid = s + (e-s)/2;
        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);
        
        root->left = BST_balanced(inorder,s,mid-1);
        root->right = BST_balanced(inorder,mid+1,e);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> inOrder;
        
        inOrderTraversal(root,inOrder);
        
        return BST_balanced(inOrder,0,inOrder.size()-1);
        
    }
};