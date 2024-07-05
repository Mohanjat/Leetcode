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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> dis;
    
        ListNode* temp = head->next;
        int d = 2;
        
        int minDis = INT_MAX;
        
        while(temp->next){
            //local maxima case
            if(head->val < temp->val && temp->val > temp->next->val){
               //check for minimum distance
                if(dis.size() > 0){
                    minDis = min(minDis, d-dis[dis.size()-1]);
                }
                dis.push_back(d);
            }
            
            //local minima case
            if(head->val > temp->val && temp->val < temp->next->val){ 
               //check for minimum distance
                if(dis.size() > 0){
                    minDis = min(minDis, d-dis[dis.size()-1]);
                }
                dis.push_back(d);
            }
            
            d++;
            temp = temp->next;
            head = head->next;
        }
        
        if(dis.size() < 2) return {-1,-1};
        
        int maxDis = dis[dis.size()-1] - dis[0];
        
        
        return {minDis,maxDis};
    }
};