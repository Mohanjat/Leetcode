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
    int cnt = 0;
    
    ListNode* reverse(ListNode* curr,ListNode* prev){
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* findMiddle(ListNode* &head){
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast){
            cnt++;
            fast = fast->next;
            slow = slow->next;
            if(fast){
                fast = fast->next;
            }
        }
        return slow;
    }
    
    
    void reorderList(ListNode* head) {
        ListNode* middleNode = findMiddle(head);
        
        ListNode* temp = head;
        int tempCnt = 1;
        
        while(tempCnt < cnt){
            temp = temp->next;
            tempCnt++;
        }
        
        temp->next = NULL;
        
        ListNode* curr = middleNode;
        ListNode* prev = NULL;
        
        ListNode* newHead = reverse(curr,prev);
        
        while(head && newHead){
            ListNode* newTemp = head->next;
            head->next = newHead;
            ListNode* newHeadTemp = newHead->next;
            newHead->next = newTemp;
            newHead = newHeadTemp;
            head = newTemp;
        }
        
    }
};