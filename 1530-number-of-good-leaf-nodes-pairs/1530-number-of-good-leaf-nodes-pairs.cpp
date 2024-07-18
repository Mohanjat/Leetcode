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
    
    void makeGraph(TreeNode* root, TreeNode* prev,unordered_map<TreeNode*,vector<TreeNode*>> &graph,unordered_set<TreeNode*> &st){
        
        //base case
        if(!root) return;
        
        //root node h to set m store kr lo
        if(root->left == NULL && root->right == NULL){
            st.insert(root); 
        }
        
        //make a connection
        if(prev != NULL){
            graph[prev].push_back(root);
            graph[root].push_back(prev);
        }
        
        makeGraph(root->left,root,graph,st);
        makeGraph(root->right,root,graph,st);
    }
    
    int countPairs(TreeNode* root, int distance) {
        //step1 -- make an undirected graph and store all the leaf nodes
        //step2 -- calculate shortest distance of all <= distance
        
        
        //time complexity == o(n^2)
        
        //make undirected graph first
        unordered_map<TreeNode*,vector<TreeNode*>> graph;
        
        unordered_set<TreeNode*> st;
        
        //need a prev node to establish connection
        makeGraph(root,NULL,graph,st);
        
        int ans = 0;
        
        //now find distance
        for(auto &it:st){
            
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(it);
            
            visited.insert(it);
            
            
            for(int level = 0; level <= distance; level++){ // at a time only go till level <= distance
                
                int size = q.size();
                
                while(size--){
                    TreeNode* temp = q.front();
                    q.pop();
                    
                    if(temp != it && st.count(temp)){ //means curr node temp leaf node h which is store in the set
                        ans++;
                    }
                    
                    for(auto & ngbr:graph[temp]){
                        if(!visited.count(ngbr)){
                            //means ngbr is not visited then push it into the q
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        
        return ans/2;
        
    }
};