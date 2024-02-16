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
    
    int maxVal(TreeNode* root){
        
        TreeNode* temp = root;
        
        if(root == NULL) return -1;
        
        while(temp->right != NULL){
            temp = temp->right;
        }
        
        return temp->val;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        //agr root null h to return null kr do 
        if(root == NULL) return NULL;
        
        if(root->val == key){
            //delete krne waali node mil chuki h
            //node delete krne ke 4 type ho skte h
            
            //1-- leaf node ho
            if(root->left == NULL && root->right == NULL){
                //null return kr do
                // delete root;
                return NULL;
            }
            else if(root->left == NULL && root->right != NULL){
                TreeNode* child = root->right;
                return child;
            }
            else if(root->left != NULL && root->right == NULL){
                TreeNode* child = root->left;
                return child;
            }
            else{
                //left aur right dono NULl nhi ho 
                //sbse phle root node ka inorder predecessor find kro
                int data = maxVal(root->left);
                
                //now replace to root value with the maxval of left tree
                root->val = data;
                
                //now delete the maxval node 
                root->left = deleteNode(root->left,data);
                
                return root;
            }
        }
        else if(key < root->val){
            //root ka value bda h to left m search kro
            //aur left side se delete hui node, root ke left m hi add honi chahiye
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            //means root ki value, key se choti h 
            //delete node hone ke baad, tree right m add hoga
            root->right = deleteNode(root->right,key);
        }
        
        return root;
        
    }
};