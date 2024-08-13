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
    
    ListNode* reverse(ListNode* prev, ListNode* curr){
        if(curr == NULL) return prev;
        
        ListNode* forward = curr->next;
        curr->next = prev;
        
       return reverse(curr,forward);
        
  
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //first of all process first k nodes
        int len = k;
        
        ListNode* temp = head;
        ListNode* prevNode = head;
        ListNode* kthNode = NULL;
        
        while(temp != NULL){
            len--;
            if(len == 0){
                kthNode = temp;
                break;
            }
            temp = temp->next;
            if(temp == NULL) return head;
        }
        
        head = temp;
        ListNode* nextNode = temp->next;
        temp->next = nullptr;
        
        ListNode* prev = NULL;
        
        head = reverse(prev,prevNode);
        
        temp = nextNode;
        
        while(temp != NULL){
            
            len = k;
            
           ListNode* tempHead = temp;
            
            while(temp != NULL){
                len--;
                if(len == 0){
                    kthNode = temp;
                    break;
                }
                temp = temp->next;
                if(temp == NULL){
                    prevNode->next = nextNode;
                    return head;
                }
            }
            
            nextNode = temp->next;
            temp->next = NULL;
            prev = NULL;
            
            prevNode->next = reverse(prev,tempHead);
            
            prevNode = tempHead;
            
            temp = nextNode;
        }
        
        
        return head;
    }
};