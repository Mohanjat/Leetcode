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
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                if(!q.empty()){
                    TreeNode* temp1 = q.front();
                    ans = temp1->val;
                    q.push(NULL);
                }
            }
            else{
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return ans;
    }
};