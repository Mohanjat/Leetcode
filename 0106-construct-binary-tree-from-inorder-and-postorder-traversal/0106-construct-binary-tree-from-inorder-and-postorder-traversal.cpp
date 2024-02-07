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
    
    int findPos(vector<int> &inorder,int element, int size){
        for(int i=0; i<size; i++){
            if(inorder[i] == element) return i;
        }
        
        return -1;
    }
    
    TreeNode* newTree(vector<int>& inorder, vector<int>& postorder,int size, int &postIndex,int start
                      ,int end){
        
        //base case
        if(start>end || postIndex < 0){
            return NULL;
        }
        
        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        
        int pos = findPos(inorder,element,size);
        
        //first we have to nodes in the right part of root because the order of the postOrder 
        //Traversal is Left Right Node that why 
        root->right = newTree(inorder,postorder,size,postIndex,pos+1,end);
        root->left = newTree(inorder,postorder,size,postIndex,start,pos-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int size = inorder.size();
        int postIndex = size-1;
        int start = 0;
        int end = size-1;
        
        return newTree(inorder,postorder,size,postIndex,start,end);
        
    }
};