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
    
    bool check(TreeNode* root, int target){
        if(root == NULL) return false;
        
        if(root->val == target) return true;
        
        bool l = false;
        bool r = false;
        if(root->val > target){
             l = check(root->left,target);
        }
        else{
             r = check(root->right,target);
        }
        
        return l || r;
    }
    
    bool solve(TreeNode* root, int target){
        
        //base case 
        if(root == NULL) return false;
        
        //curr node ko process kr lo
        int newTarget = target-root->val;
        
        if(newTarget > root->val){
            //search in the right part
           if(check(root->right,target-root->val)){
               return true;
           }    
        }
        else{
            if(check(root->left,target-root->val)){
               return true;
            }   
        }
       
        
        //left se answer le aao
        bool left = solve(root->left, target);
        //right se answer le aao
        bool right = solve(root->right,target);
        
        return left || right;
        
    }
    
    
        void inOrderTraversal(TreeNode* root,vector<int> &v){
        if(root == NULL) return;
        
        inOrderTraversal(root->left,v);
        v.push_back(root->val);
        inOrderTraversal(root->right,v);
        }
    
    bool findTarget(TreeNode* root, int k) {
        
        //the intitution is simple-- yaa to answer left se aayega ya phir right se ayega
        //ya phir root ko include kr aayega
       // return solve(root,k);
        
        vector<int> inorder;
        
        inOrderTraversal(root,inorder);
        
        int s = 0;
        int e = inorder.size()-1;
        
        while(s<e){
            if(inorder[s]+inorder[e] == k){
                return true;
            }
            
            if(inorder[s]+inorder[e] > k){
                e--;
            }
            else{
                s++;
            }
        }
        
        return false;
        
        
        // unordered_map<int,int> map;
        
//         for(int i=0; i<inorder.size(); i++){
            
//             //check if the value is present in map or not
//             if(map.find(k-inorder[i]) == map.end()){
//                 //means value nhi mili h to entry create kr do
//                 map[inorder[i]] = i;
//             }else{
//                 //means we found 2 values that is equal == target
//                 return true;
//             }
//         }
//         return false;
    }
};