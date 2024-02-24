class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        if(preorder.empty()) return false;
        //last element process krne ke liye
        preorder += ',';
        int l = preorder.length();
        
        int capacity  = 1;
        
        for(int i=0; i<l; i++){
            
            if(preorder[i] != ',') continue;
            
            capacity--;
            
            if(capacity < 0) return false;
            
            if(preorder[i-1] != '#') capacity += 2;
        }
        
        return capacity == 0;        
    }
};