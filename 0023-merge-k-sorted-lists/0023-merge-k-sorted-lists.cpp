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

class Node{
    public:
    int data;
    int row;
    ListNode* temp;
    
    Node(int v,int r, ListNode* t){
        data = v;
        row = r;
        temp = t;
    }
};

class comparator{
    public:
    
    bool operator()(Node*a , Node*b){
        return a->data > b->data;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<Node*,vector<Node*>,comparator>pq;
        
        //process first k elements
        int size = lists.size();
        
        for(int i=0; i<size; i++){
            
            ListNode* temp1 = lists[i];
            if(temp1 == NULL) continue;
            
            Node* newNode = new Node(temp1->val,i,temp1);
            
            pq.push(newNode);
        }
        
        //now process remaining n-k elements
        vector<int> ans;
        
        while(!pq.empty()){
            
            Node* top = pq.top();
            pq.pop();
            
            int topElement = top->data;
            int topRow = top->row;
            ListNode* topCol = top->temp;
            
            //here top element is smaller element so push it into the ans;
            ans.push_back(topElement);
            
            if(topCol->next != NULL){
                //then insert the new element in the priority queue
                topCol = topCol->next;
                Node* newNode = new Node(topCol->val, topRow, topCol);
                pq.push(newNode);
            }
            
        }
        
        
        
        ListNode* head = NULL;
        ListNode* lastNode = NULL;
        
        for(int i=0; i<ans.size(); i++){
            
            ListNode* newNode = new ListNode(ans[i]);
            
            if(lastNode == NULL){
               head = newNode;
               lastNode = newNode;
            }
            else{
                lastNode->next = newNode;
            }
            lastNode = newNode;
        }
        
        return head;
    }
};