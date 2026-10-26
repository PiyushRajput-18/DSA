class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int n = nums.size();
     int maxproduct = nums[0];
      int minproduct = nums[0];
      int ans = nums[0];
      if(n==1){
        return nums[0];
      }
      for(int i=1;i<n;i++){
            if(nums[i]<0){
               int temp = maxproduct;
                maxproduct  = minproduct;
                minproduct =temp;
                
            } 

         maxproduct = max(nums[i],nums[i]*maxproduct);
         minproduct = min(nums[i],nums[i]*minproduct);

         ans = max(ans,maxproduct);

      }
      return ans;
    }
};