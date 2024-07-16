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
    
    TreeNode* LCA(TreeNode* root, int s, int d){
        if(!root) return NULL;
        
        if(root->val == s) return root;
        
        if(root->val == d) return root;
        
        TreeNode* l = LCA(root->left,s,d);
        TreeNode* r = LCA(root->right,s,d);
        
        if(l && r) return root;
        
        return l ? l : r;
              
    }
    
    bool findPath(TreeNode* lca, int val, string &str){
        if(!lca) return false;
        
        if(lca->val == val) return true;
        
        str.push_back('L');
        if(findPath(lca->left,val,str)){
            return true;
        }
        
        str.pop_back();
        
        str.push_back('R');
        
        if(findPath(lca->right,val,str)){
            return true;
        }
        
        str.pop_back();
        
        return false;
        
     }
    
    string getDirections(TreeNode* root, int startValue, int destValue){
        TreeNode* lca = LCA(root,startValue,destValue);
        
        string lcaToS = "";
        string lcaToD = "";
        
        findPath(lca,startValue,lcaToS);
        findPath(lca,destValue,lcaToD);
        
        int len = lcaToS.length();
        cout<<len<<endl;
        std::string result = "";
        
        for(int i=0; i<len; i++){
            result.push_back('U');
        }
        
        result = result + lcaToD;
        
        return result;
    }
};