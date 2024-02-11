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
    
    int leftHeight(TreeNode* root){
        if(root == 0) return 0;
        
        int lefth = leftHeight(root->left);
        int righth = leftHeight(root->right);
        
        return max(lefth, righth) +1;
    }
    
    int height(TreeNode* root, bool &ans){
        
        if(!root) return 0;
        
       int lh = height(root->left,ans);
       int rh = height(root->right,ans);
       
        if(abs(lh-rh) > 1) ans = false;
        
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        
//         //base case 
//         if(root == NULL){
//             //agr hum last tk phuch gye h aur false return nhi h iska mtlb tree balanced ho skta h
//             return true;
//         }
        
//         //let calulate the left part height 
//         int leftH = leftHeight(root->left);
//         cout<<"height of left part "<<leftH<<endl;
//         int rightH = leftHeight(root->right);
//         cout<<"height of right part "<<rightH<<endl;
        
//         if(abs(leftH-rightH) > 1){
//             return false;
//         }
        
//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);
        
//         return left & right;
        
        bool ans = true;
        
        height(root,ans);
        
        return ans;
        
    }
};