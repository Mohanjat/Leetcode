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
    
    void findSum(TreeNode* root,long &targetSum,long &temp,long& sum){
        
        if(root == NULL) return ;
        
        //phle isliye add ki h value kyo leaf node ke case ke ander 
        //equal condition check kiye bina hi return ho jaa rhy thy
        sum += root->val;
        
        if(targetSum == sum) temp++;
        
      
        findSum(root->left,targetSum,temp,sum);
        
        findSum(root->right,targetSum,temp,sum);
        
        sum -= root->val;
    }
    
    void calSum(TreeNode* root, long &targetSum, long&ans){
        if(root == NULL) return;
        
        //first of all try to calclue sum including curr node
        long temp = 0;
        long sum = 0;
        
        findSum(root,targetSum,temp,sum);
        
        // if(temp == 0) cout<<root->val<<" ";

        ans += temp;
        
        //answer left m bhi check kr lo
        calSum(root->left,targetSum,ans);
        //right m bhi check kr lo bhai
        calSum(root->right,targetSum,ans);
        
    }
    
    int pathSum(TreeNode* root, long targetSum) {
        
        //the thought is --- yaa to answer left se ayega 
        //ya phir right se ayega 
        //ya phir curr node ko include krke aayega
        
        long ans = 0;
        
        calSum(root,targetSum,ans);
        
        return ans;
        
    }
};