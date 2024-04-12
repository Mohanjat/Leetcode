class Solution {
public:
    
    void findNextGreater(vector<int>&nextGreater, vector<int> &height){
        stack<int> st;
        st.push(-1);
        
        for(int i=height.size()-1; i>=0; i--){
            int curr = height[i];
            int maxi = INT_MIN;
            while(st.top() < curr){
                if(st.top() == -1) break;
                maxi = max(maxi,st.top());
                st.pop();
            }
            //now top element is the next greater element
           
            nextGreater[i] = max(maxi,st.top());
        
            
            //push the curr element in the stack
            st.push(curr);
            
        }
        
    }
    
    void waterQuantity(vector<int>&nextGreater,vector<int>&height,int &ans){
        
        int i = 0;
        int j = 0;
        
        while(j<height.size()){
            if(nextGreater[i] == -1){
                i++;
                j++;
                continue;
            }
            if(i == j && height[i] == 0){
                i++;
                j++;
                continue;
            }
            
            //now reach out to the greater element of the ith index 
            int element = nextGreater[i];
            int midValue = 0;
            
            while(true){
                j++;
                if(height[j] == element){
                    break;
                }
                midValue += height[j];
            }
            
            //height[j] is the possition having greater element
            //now calculate the area
            int width = j-i-1;
            
            int area = width*min(height[i],height[j]) - midValue;
            
            ans += area;
            
            i = j;
            
        }
    }
    
    int trap(vector<int>& height) {
        
        vector<int> nextGreater(height.size());
        
        findNextGreater(nextGreater,height);
        
//         for(int i=0; i<nextGreater.size(); i++){
//             cout<<nextGreater[i]<<" ";
//         }cout<<endl;
        
        int ans = 0;
        
        waterQuantity(nextGreater,height,ans);
        
        return ans;
    }
};