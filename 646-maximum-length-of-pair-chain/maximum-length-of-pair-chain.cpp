class Solution {
public:
int dp[1001][1001];
int solve(int i,int p,vector<vector<int>>& nums){
    if(i>=nums.size()){
        return 0;
    }
    if (dp[i][p + 1] != -1)
            return dp[i][p + 1];
    int take =0;
    if(p==-1||nums[p][1]<nums[i][0]){
        take = 1+solve(i+1,i,nums);
    }
    int skip = solve(i+1,p,nums);
    if(p!=-1){
        dp[i][p+1]=max(take,skip);
    }
    return max(take,skip);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
       return solve(0,-1,pairs);
    }
};