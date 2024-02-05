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
    
    void levelOrderTraversal(TreeNode* root, int &ans){
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        int level = 0;
        
        int maxi = INT_MIN;
        int sum = 0;
//         sum += root->val;
        
//         maxi = max(maxi,sum);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                //agr temp ki value NULL hai to iska mtlb h ki hum next level pr aa gye
                level++;
                //now check if maxi is greater than sum than update the ans and maxi
                if(maxi<sum){
                    ans = level;
                    maxi = sum;
                }
                
                sum = 0;
                
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                //sum ke ander val add kr do
                sum += temp->val;
                //and left and right ko queue ke ander push kr lo
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    
    int maxLevelSum(TreeNode* root) {
        //this is an level order traversal type question
        
        int ans = 1;
        levelOrderTraversal(root,ans);
        return ans;
    }
};