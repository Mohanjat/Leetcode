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
    
    
    bool isBalanced(TreeNode* root) {
        
        //base case 
        if(root == NULL){
            //agr hum last tk phuch gye h aur false return nhi h iska mtlb tree balanced ho skta h
            return true;
        }
        
        //let calulate the left part height 
        int leftH = leftHeight(root->left);
        cout<<"height of left part "<<leftH<<endl;
        int rightH = leftHeight(root->right);
        cout<<"height of right part "<<rightH<<endl;
        
        if(abs(leftH-rightH) > 1){
            return false;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        return left & right;
        
    }
};