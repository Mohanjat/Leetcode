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
    void lot(TreeNode* root,vector<int> &v){

    queue<TreeNode*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            // cout<<endl;
            v.push_back(-200);
          if(!q.empty()){
            q.push(NULL);
          }
        }
        else{
            
        // cout<<temp->data<<" ";
        v.push_back(temp->val);
        if(temp->left){
          q.push(temp->left);
        }
        if(temp->right){
          q.push(temp->right);
        }
        }
    }
     // v.push_back(-1);
}

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        // vector<vector<int>> ans;
        
        vector<int> v;
        lot(root,v);
        
        int cnt = 0;
        
//          for(int i=0; i<v.size(); i++){
//             cout<<"val "<<v[i]<<" ";
//          }
        
        for(int i=0; i<v.size(); i++){
        
            vector<int> temp;
            
            while(v[i] != -200){
                temp.push_back(v[i]);
                i++;
            }
            
            if(cnt % 2 == 0){
                ans.push_back(temp);
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);                
            }
            
            cnt++;

        }
        
        return ans;
    }
};