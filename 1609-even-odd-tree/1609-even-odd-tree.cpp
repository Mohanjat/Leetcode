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
    
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        int cnt = 0;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            if(cnt&1){
                //odd index
                //values should be even and decreasing order;
                int dec = INT_MAX;
                
                while(true){
                    
                    TreeNode* temp = q.front();
                    q.pop();
                    
                    if(temp == NULL) break;
                    if((temp->val&1) || (dec <= temp->val)){
                        //mtlb value odd h 
                        return false;
                    }
                    
                    
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    //dec ko update kr do 
                    dec = temp->val;
                }
                
                //agr queue empty nhi h to null push kr do
                if(!q.empty()) q.push(NULL);
                cnt++;
                
            }
            else{
                //even index
                //values should be odd and increasing order
                int inc = INT_MIN;
             
                while(true){
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp == NULL) break;
                    
                    if(!(temp->val&1) || (inc >= temp->val)){
                        return false;
                    }
                    
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    
                    //inc ko update
                    inc = temp->val;
                }
                
                //agr queue emtpy nhi h to null push kr do
                if(!q.empty()) q.push(NULL);
                cnt++;
            }
        }
        
        return true;
    }
};