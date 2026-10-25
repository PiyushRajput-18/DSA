class Solution {
public:
int dp[101][101];
  int solve(int i, int j, int m,int n,vector<vector<int>>& obstacleGrid){
    if(i==m-1&&j==n-1){
        return 1;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
     
    if((i<0||i>m-1)||(j<0||j>n-1)){
        return 0;
    }
    int down =0;
    if(i+1<m){
    if(obstacleGrid[i+1][j]!=1){
        down = solve(i+1,j,m,n,obstacleGrid);
    }
    }
    int right =0;
    if(j+1<n){
    if(obstacleGrid[i][j+1]!=1){
        right = solve(i,j+1,m,n,obstacleGrid);
    }
    }
    return dp[i][j]=right+down;
  }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        return solve(0,0,m,n,obstacleGrid);

    }
};