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
        
        //Approach#3 using Recursion;
        
        //base case
        if(head == NULL || head->next == NULL) return head;
        
        //hum head prr h aur head se bola h ki head se aage waala answer le aao
        ListNode* nextNode = removeNodes(head->next);
        
        //check kr lo nextNode ki val head ki val se bdi to nhi h 
        if(nextNode->val > head->val){
            //head ko delete kr do
            delete head;
            return nextNode;
        }
        
        head->next = nextNode;
        return head;
        
        
        //Approac#2 using Stack
//         stack<ListNode*> st;
//         ListNode* curr = head;
        
//         while(curr){
//             while(!st.empty() && st.top()->val < curr->val){
//                 st.pop();
//             }
//             st.push(curr);
//             curr = curr->next;
//         }
        
//         ListNode* newHead = st.top();
//         st.pop();
        
//         while(!st.empty()){
//             ListNode* tempNode = st.top();
//             st.pop();
//             tempNode->next = newHead;
//             newHead = tempNode;
//         }
        
//         return newHead;
        
        
        
        //Approach#1 using Reversal
      
//        ListNode* prev1 = NULL;
//        head = reverse(head,prev1);
        
//        ListNode* temp = head;
        
//         int maxi = INT_MIN;
//         ListNode* prev = temp;
        
//         maxi  = temp->val;
//         temp = temp->next;
        
//         while(temp){
//             if(temp->val < maxi){
//                 //delete the node
//                 if(!temp->next){
//                     prev->next = nullptr;
//                 }
                
//                 ListNode* newTemp = temp->next;
//                 temp->next = nullptr;
//                 prev->next = newTemp;
//                 temp = newTemp;
//             }
//             else{
//                 //update the maxi and aage bd jaao
//                 maxi = temp->val;
//                 temp = temp->next;
//                 prev = prev->next;
//             }
//         }
        
//         prev = nullptr;
//         head = reverse(head,prev);
        
//         return head;
        
    }
};