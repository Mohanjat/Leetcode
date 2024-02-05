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
    
    void solve(TreeNode* root,vector<vector<int>> &ans, vector<int> &temp,int &targetsum,int &sum){
        //base case
        if(root == NULL){   
            return;
        }
        //means we are at leaf node
        if(root->left == NULL && root->right == NULL){
            
               temp.push_back(root->val);
               sum += root->val;   
            //agr sum ki value targetsum ke equal h to temp ko ans ke ander store krwa lo
            if(sum == targetsum){ 
                ans.push_back(temp);
             }
           temp.pop_back();
           sum -= root->val;            
            return;
        }
        
   
        
        //temp ke ander data store kr lo
        temp.push_back(root->val);
        
        sum += root->val;
        
        solve(root->left,ans,temp,targetsum,sum);
        
        //wapis jaate time //means this is backtraking
        temp.pop_back();
        sum -= root->val;
        
        //lets check in the right part
        temp.push_back(root->val);
        
        sum += root->val;     
        
        solve(root->right,ans,temp,targetsum,sum);
        
        temp.pop_back();
        sum -= root->val;
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        int sum  = 0;
        solve(root,ans,temp,targetSum,sum);
        
        return ans;
    }
};