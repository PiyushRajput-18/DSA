class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int small = *min_element(nums.begin(),nums.end());
        int large = *max_element(nums.begin(),nums.end());
        int ans =0;
       
   sort(nums.begin(), nums.end());   
     int median;

if(n % 2 == 1) {
    median = nums[n/2];
}
else {
    median = (nums[n/2 - 1] + nums[n/2]) / 2;
}
     for(int i=0;i<n;i++){
        ans+=(abs(median-nums[i]));
     }
     return ans;
    }
};