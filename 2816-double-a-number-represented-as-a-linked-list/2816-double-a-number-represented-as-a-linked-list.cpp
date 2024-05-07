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
    
    ListNode* solve(ListNode*temp,int&digit){
        if(!temp) return nullptr;
        
        ListNode* nextNode = solve(temp->next,digit);
        
        int value = (temp->val)*2 + digit;
        
        int newVal = value%10;
        
        temp->val = value%10;
        
        digit = value/10;
            
        return temp;
            
    }
    
    ListNode* doubleIt(ListNode* head){
        int digit = 0;
        ListNode*temp = head;
        head = solve(temp,digit);
        
        while(digit>0){
            int rightDigit = digit%10;
            //create a new node of this
            ListNode* newNode = new ListNode(rightDigit);
            
            newNode->next = head;
            head = newNode;
            digit = digit/10;
        }
        
        return head;
        
    }
};