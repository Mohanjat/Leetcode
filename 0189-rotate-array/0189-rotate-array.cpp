class Solution {
public:
    void rotate(vector<int>& nums, int k){
        
        vector<int>temp;
        
        if(k>=nums.size()){
            int t = k%nums.size();
            k = t;
        }
        
        int j = nums.size()-k;
        int i=0;
        while(i<j){
            int lastEle = nums.front();
            nums.erase(nums.begin());
            temp.push_back(lastEle);
            i++;
        }
        
        for(int i=0; i<temp.size(); i++){
            nums.push_back(temp[i]);
        }
        
    }
};