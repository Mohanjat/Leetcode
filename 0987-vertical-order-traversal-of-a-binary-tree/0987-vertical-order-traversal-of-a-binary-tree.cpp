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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        map<int,map<int,multiset<int>>> Map; //col -> (row -> [a,b,c....])
        
        queue<pair<TreeNode*,pair<int,int>>> q; //node, {col,row}
         
        q.push({root,{0,0}});
        
        while(!q.empty()){
            
            auto pair = q.front();
            q.pop();
            
            auto&node = pair.first;
            auto&cordinates = pair.second;
            int&row = cordinates.first;
            int&col = cordinates.second;
            
            Map[col][row].insert(node->val);
            
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
           
        }
        
        //now the on the map and store values in the ans vector
        for(auto i:Map){
            auto&colMap = i.second;
            vector<int>temp;
            for(auto j:colMap){
                auto&mulSet = j.second;
                //copy all the multi set data into the temp vector
                temp.insert(temp.end(),mulSet.begin(),mulSet.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};