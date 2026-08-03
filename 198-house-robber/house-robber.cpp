class Solution {
public:
int dp[101];
int solve(int i,vector<int>&nums){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int steal = nums[i]+solve(i+2,nums);
    int skip = solve(i+1,nums);
    return dp[i]=max(steal,skip);
}
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int i=0;
        int maxprofit = solve(i,nums);
        return maxprofit;    
    }
};