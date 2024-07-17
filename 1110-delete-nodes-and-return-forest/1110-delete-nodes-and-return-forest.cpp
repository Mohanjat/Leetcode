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
    
TreeNode* deleteNodes(TreeNode* root, unordered_map<int, int>& mp, vector<TreeNode*>& ans) {
    if (!root) return NULL;
    
    root->left = deleteNodes(root->left, mp, ans);
    root->right = deleteNodes(root->right, mp, ans);
    
    if (mp.find(root->val) != mp.end()) {
        if(root->left) {
            ans.push_back(root->left);
        }
        if (root->right) {
            ans.push_back(root->right);
        }
        return NULL;
    }
    
    else{
         return root;
    }
    
   
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    
    vector<TreeNode*> ans;
    
    unordered_map<int, int> mp;
    for (auto i : to_delete) {
        mp[i]++;
    }
    
    TreeNode* r = deleteNodes(root, mp, ans);
    
    if(mp.find(root->val) == mp.end()){
        ans.push_back(root);
    }
    
    return ans;
    
}


};