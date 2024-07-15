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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> childNode;  //this values can not be a root;
        
        for(auto &i:descriptions){
            int parent = i[0];
            int child = i[1];
            int isChild = i[2];
            
            //first of all the create the nodes if they are not present in the mp
            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }
            
            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }
            
            //now connect the parent node to the child node
            if(isChild == 1){
                //it will a left child
                mp[parent]->left = mp[child];
            }
            else{
                //it will be a right child
                mp[parent]->right = mp[child];
            }
            
            //insert the child in the set 
            childNode.insert(child);
        }
        
        //now find out the root node by traversing the descriptions
        for(auto &i:descriptions){
            if(childNode.find(i[0]) == childNode.end()){
                //means the curr value definatly not a child of any node
                return mp[i[0]];
            }
        }
        
        return NULL;
    }
};