/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* createBST(vector<int>&v,int s, int e){
        //base case 
        if(s>e) return NULL;
        
        int mid = s + (e-s)/2;
        
        int element = v[mid];
        
        TreeNode* root = new TreeNode(element);
        
        root->left = createBST(v,s,mid-1);
        root->right = createBST(v,mid+1,e);
        
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        ListNode* temp = head;
        vector<int> linkedList;
        
        while(temp != nullptr){
          
            linkedList.push_back(temp->val);
            temp = temp->next;
        }

        return createBST(linkedList,0,linkedList.size()-1);
    }
};