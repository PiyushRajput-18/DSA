class Solution { 
public: 
    int firstMissingPositive(vector<int>& nums) { 
        int n = nums.size(); 
        
        vector<int> temp(n + 1, 0); 
 
        for(int i = 0; i < n; i++){ 
            if(nums[i] > 0 && nums[i] < n + 1){ 
                temp[nums[i]]++; 
            } 
        } 
        
        int ans = 0; 
        
        for(int i = 1; i < n + 1; i++){ 
            if(temp[i] == 0){ 
                ans = i; 
                break; 
            } 
        } 
        
        if(ans == 0){
            ans = n + 1;
        }
           
        return ans; 
    } 
};