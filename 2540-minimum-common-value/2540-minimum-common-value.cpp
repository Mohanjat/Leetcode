class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int i=0;
        int j=0;
        int ans = -1;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                ans = nums1[i];
                break;
            }
            
            if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
        
       
//         set<int> s;
        
//         for(int i=0; i<nums1.size(); i++){
//             s.insert(nums1[i]);
//         }
        
//         int ans = -1;
        
//         for(int i=0; i<nums2.size(); i++){
//             if(s.find(nums2[i]) != s.end()){
//                 ans = nums2[i];
//                 break;
//             }
//         }
//      return ans;  
    }
};