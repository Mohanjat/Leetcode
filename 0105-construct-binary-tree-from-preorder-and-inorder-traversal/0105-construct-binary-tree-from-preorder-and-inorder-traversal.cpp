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
    
    int findPos(vector<int> &inorder,int element,int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element)return i;
        }
        return -1;
    }
    
    TreeNode* build_New_tree(vector<int> &preorder, vector<int> &inorder,int &preIndex,int n,
    int inS,int inE){
        
        //base case 
        if(inS > inE || preIndex >= n){
            return NULL;
        }
        
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        
        int pos = findPos(inorder,element,n);
        
        root->left = build_New_tree(preorder,inorder,preIndex,n,inS,pos-1);
        root->right = build_New_tree(preorder,inorder,preIndex,n,pos+1,inE);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //use map to find positiong of elemetn in the Inorder
        
        int preIndex = 0;
        int n = inorder.size();
        int inS = 0;
        int inE = inorder.size()-1;
        
        return build_New_tree(preorder,inorder,preIndex,n,inS,inE);
    }
};