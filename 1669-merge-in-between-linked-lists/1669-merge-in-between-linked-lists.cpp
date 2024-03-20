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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* newEnd = NULL;
        ListNode* newStart = NULL;
        
        ListNode* temp = list1;
        
        int cnt = 1;
        
        while(temp != NULL){
          
             if(cnt == a){
                 newEnd = temp;
                 if(temp) temp = temp->next;
                 newEnd->next = NULL;
             }
            if(cnt == b){
                if(temp) newStart = temp->next;
                temp->next = NULL;
                break;
            }
            
            temp = temp->next;
            cnt++;
            
        }
        
        newEnd->next = list2;
        
        ListNode* temp2 = list2;
        
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        
        temp2->next = newStart;
        
        return list1;
        
    }
};