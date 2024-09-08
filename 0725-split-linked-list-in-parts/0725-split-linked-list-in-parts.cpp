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
    
    int findLen(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        
        while(temp){
            cnt++;
            temp = temp->next;
        }
        
        return cnt;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        
        int i = 0;
        
        ans[i] = head;
        i++;
        
        int len = findLen(head);
        
        int divisor = (len/k);
        
        int rem = len % k;
    
        while(i<k && head != NULL){
            
            int temp = divisor;
            
            if(rem > 0){
                temp++;
                rem--;
            }
            
            while(temp > 1 && head != NULL){
                head = head->next;
                temp--;
            }
            
            ListNode* newHead = head->next;
            head->next = nullptr;
            
            head = newHead;
            
            ans[i] = head;
            
            i++;
        }
        
        while(i<k){
            ans[i] = NULL;
            i++;
        }
        
        return ans;
    }
};