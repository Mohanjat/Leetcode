/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 
     void solve(ListNode* &head, bool &ans){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
               fast = fast->next;
               slow = slow->next;
            }
            if(fast == slow){
                ans = true;
                break;
            }
            if(fast == NULL){
                ans = false;
                break;
            }

        }

       // return true;

    }
public:
    bool hasCycle(ListNode *head) {

       bool ans;
        solve(head,ans);

       return ans;
        
    }
};