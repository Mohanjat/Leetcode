class Node{
    public:
    char ch;
    int cnt;
    
    Node(char c, int cnt){
        ch = c;
        this->cnt = cnt;
    }
};

class comparator{
    public:
    
    bool operator()(Node* a, Node* b){
        return a->cnt < b->cnt;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        //first of all push char a,b,c with their count into the maxHeap
        
        priority_queue<Node*,vector<Node*>,comparator> maxHeap;
        
        //push char a into the max heap with its count value
        if(a>0) maxHeap.push(new Node('a',a));
        if(b>0) maxHeap.push(new Node('b',b));
        if(c>0) maxHeap.push(new Node('c',c));
        
        string ans = "";
        
        while(maxHeap.size() > 1){
            
            Node* first = maxHeap.top();
            maxHeap.pop();
            Node* second = maxHeap.top();
            maxHeap.pop();
            
            //process first element now
            char firstChar = first->ch;
            int firstCnt = first->cnt;
            
            if(!ans.empty() && ans[ans.length()-1] != firstChar && firstCnt>1){
                ans += firstChar;
                ans += firstChar;
                firstCnt -= 2;
            }
            else if(ans.empty() && firstCnt>1){
                ans += firstChar;
                ans += firstChar;
                firstCnt -= 2;
            }
            else{
                ans += firstChar;
                firstCnt -= 1;
            }
           //now push again first element if the firstcnt is greater than 0
            if(firstCnt > 0){
                maxHeap.push(new Node(firstChar,firstCnt));
            }
            
            //now process second element;
            char secondChar = second->ch;
            int secondCnt = second->cnt;
            
            ans += secondChar;
            secondCnt--;
            
//             if(secondCnt>1){
//                 ans += secondChar;
//                 ans += secondChar;
//                 secondCnt -= 2;
//             }
//             else{
//                 ans += secondChar;
//                 secondCnt -= 1;
//             }
            
            if(secondCnt > 0) maxHeap.push(new Node(secondChar,secondCnt));
        }
        
        if(maxHeap.size() == 1){
            Node* temp = maxHeap.top();
            maxHeap.pop();
            
            char tempChar = temp->ch;
            int tempCnt = temp->cnt;
            
            if(!ans.empty() && tempCnt>1 && ans[ans.length()-1] != tempChar){
                ans += tempChar;
                ans += tempChar;
            }
            else if(ans.empty() && tempCnt>1){
                 ans += tempChar;
                ans += tempChar;
            }
            else{
                ans += tempChar;
            }
        }
        
        return ans;
        
    }
};