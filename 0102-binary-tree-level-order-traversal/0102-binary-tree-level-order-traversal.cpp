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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        // vector<int> v;
        // v.push_back(root->val);
        
        while(!q.empty()){
            vector<int> v;
            TreeNode* temp = q.front(); q.pop();
            
            while(temp != NULL){
                // store answer in the ans vector
               
                //delete all the element from the vector v
                // v.erase(v.begin(),v.end());
                //push the node into the temp vector
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                temp = q.front(); q.pop();
            }
            
            ans.push_back(v);
            
            if(!q.empty()){
               q.push(NULL);
            }
            
        }
        
        return ans;
        
    }
};