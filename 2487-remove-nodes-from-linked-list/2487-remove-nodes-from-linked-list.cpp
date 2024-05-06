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
class Solution {
public:
    
    ListNode* reverse(ListNode* head,ListNode*prev){
        if(!head)return prev;
        
        ListNode* curr = head;
        head = head->next;
        curr->next = prev;
        
        return reverse(head,curr);
    }
    
    ListNode* removeNodes(ListNode* head){
      
       ListNode* prev1 = NULL;
       head = reverse(head,prev1);
        
       ListNode* temp = head;
        
        int maxi = INT_MIN;
        ListNode* prev = temp;
        
        maxi  = temp->val;
        temp = temp->next;
        
        while(temp){
            if(temp->val < maxi){
                //delete the node
                if(!temp->next){
                    prev->next = nullptr;
                }
                
                ListNode* newTemp = temp->next;
                temp->next = nullptr;
                prev->next = newTemp;
                temp = newTemp;
            }
            else{
                //update the maxi and aage bd jaao
                maxi = temp->val;
                temp = temp->next;
                prev = prev->next;
            }
        }
        
        prev = nullptr;
        head = reverse(head,prev);
        
        return head;
        
    }
};