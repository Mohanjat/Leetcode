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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* newNode = NULL;
        ListNode* newNodeHead = NULL;
        
        int sum = 0;
        
        head = head->next;
        
        while(head){
           if(head->val == 0){
               ListNode* temp = new ListNode(sum);
               if(newNode == NULL){
                   newNode = temp;
                   newNodeHead = newNode;
               }
               else{
                   newNode->next = temp;
                   newNode = newNode->next;
               }
               
               sum = 0;
               
           }
            
           else{
               sum += head->val;
           }
            
            head = head->next;
            
        }
        
        return newNodeHead;
        
    }
};