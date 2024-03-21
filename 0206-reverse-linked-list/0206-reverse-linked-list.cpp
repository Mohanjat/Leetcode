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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
        
        
//         vector<int> v;
        
//         ListNode* temp = head;
        
//         while(temp){
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         head = temp;
//         temp = NULL;
        
//         for(int i=v.size()-1; i>=0; i--){
//             if(temp == NULL){
//                 temp = new ListNode(v[i]);
//                 head = temp;
//                 continue;
//             }
//             ListNode* newNode = new ListNode(v[i]);
//             temp->next = newNode;
//             temp = newNode;
//         }
//         return head;
    }
};