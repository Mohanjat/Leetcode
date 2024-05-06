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
      
       ListNode* prev = NULL;
       head = reverse(head,prev);
        
       ListNode* temp = head;
        
        int maxi = INT_MIN;
        
        ListNode* newHead = NULL;
        ListNode* newTemp = newHead;
        
        while(temp){
            if(temp->val < maxi){
                //delete the node
                temp  = temp->next;
            }
            else{
                //update the maxi and aage bd jaao
                ListNode* tempNode = new ListNode(temp->val);
                if(!newHead){
                    newHead = tempNode;
                    newTemp = newHead;
                }
                else{
                    newTemp->next = tempNode;
                    newTemp = tempNode;
                }
                
                maxi = temp->val;
                temp = temp->next;
            }
        }
        
        prev = nullptr;
        newHead = reverse(newHead,prev);
        
       // while(newHead){
       //     cout<<newHead->val<<" ";
       //     newHead = newHead->next;
       // }cout<<endl;
        
        return newHead;
        
    }
};