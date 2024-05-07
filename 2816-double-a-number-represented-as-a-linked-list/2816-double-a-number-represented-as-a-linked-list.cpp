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
        
        //Approach#3 left to right using one pointer
        
        
        //intitution is that carry sirf tb hi aayega tb node->val >= 5 hogi 
        //to bhai phle hi check kr lo na ki curr se next waali node ki value greater than 5 se bhdi to nhi agr h to phle hi ek carry curr node m add kr do simple is that
        
        //one corner case is that agr phli hi node ki value 5 ya 5 se bdi hui to 
        //handle seperately
        
        ListNode* curr = head;
        
        if(head->val>=5){
            ListNode* firstNode = new ListNode(1);
            firstNode->next = head;
            head = firstNode;
        }
        
        while(curr != NULL){
            curr->val = (curr->val*2)%10;
            
            if(curr->next != nullptr && curr->next->val >= 5){
                //mtlb this is kind of absolute prediction that
                //pkka carry aane waala h to usko phle hi add kr do
                curr->val += 1;
            }
            curr = curr->next;
        }
        return head;
        
        
        
        //Approach#2 traverse only Left to Right using two pointers
    
//         ListNode* curr = head;
//         ListNode* prev = nullptr;
        
//         while(curr != NULL){
//             int value = (curr->val)*2;
            
//             if(value<10){ //normal case where value is 1-9 direct add this 
//                 curr->val = value;
//             }
//             //add extra carry to the previous node
//             else if(prev == NULL){//we are at first node and there is carry {
//                 ListNode* newNode = new ListNode(1);
//                 newNode->next = curr;
//                 head = newNode;
//                 //make sure to update the curr value with the right most digit of value
//                 curr->val = value%10;
//             }
//             else{
//                 curr->val = value%10;
//                 //if value is greater then 10, then carry will definetly 1
//                 prev->val += 1;
//             }
//             prev = curr;
//             curr = curr->next;
//         }
        
//         return head;
        
        
        //Approach#1 using Recursion
        
//         int digit = 0;
//         ListNode*temp = head;
//         head = solve(temp,digit);
        
//         while(digit>0){
//             int rightDigit = digit%10;
//             //create a new node of this
//             ListNode* newNode = new ListNode(rightDigit);
            
//             newNode->next = head;
//             head = newNode;
//             digit = digit/10;
//         }
        
//         return head;
    }      
};