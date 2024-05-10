class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int cnt = 0;
        int firstEle = arr[0];
        int element = 1;
        while(element<firstEle){
            cnt++;
            if(cnt == k){
                return element;
            }
            element++;
        }
        
        for(int i=1; i<arr.size(); i++){
            int ele = arr[i-1]+1;
            while(ele < arr[i]){
                cnt++;
                if(cnt == k) return ele;
                ele++;
            }
        
        }
        
        //if cnt == 0 means array is having all the elements
        int newEle = arr[arr.size()-1]+1;
        while(true){
            cnt++;
            if(cnt == k) return newEle;
            newEle++;
        }
        
        return 0;
    }
};