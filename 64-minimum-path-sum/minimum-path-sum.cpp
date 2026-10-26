class Solution {
public:
int dp[201][201];
int solve(int i, int j, int m, int n,vector<vector<int>>& grid){
    if(i==m-1&&j==n-1){
        return grid[i][j];
    }
   if((i<0||i>m-1)||(j<0||j>n-1)){
        return INT_MAX;
   }  
   if(dp[i][j]!=-1){
    return dp[i][j];
   }   
   int right =(solve(i,j+1,m,n,grid));
   int down =(solve(i+1,j,m,n,grid));
   return dp[i][j]=grid[i][j]+min(right,down);  
}
    int minPathSum(vector<vector<int>>& grid) {
     memset(dp,-1,sizeof(dp));
        int m = grid.size();
        int n = grid[0].size();
    int result =  solve(0,0,m,n,grid);
    return result;  
    }
};




// class Solution {
// public:
// int dp[16][16];
// int solve(int i, int j, int m, int n,vector<vector<int>>& grid){
//     if(i==m-1&&j==n-1){
//         return grid[i][j];
//     }
//    if((i<0||i>m-1)||(j<0||j>n-1)){
//         return 0;
//    }  
//    if(dp[i][j]!=-1){
//     return dp[i][j];
//    }   
//    int right = grid[i][j]*(solve(i,j+1,m,n,grid));
//    int down = grid[i][j]*(solve(i+1,j,m,n,grid));
//    return dp[i][j]=max(right,down);  
// }
//     int maxProductPath(vector<vector<int>>& grid) {
//         memset(dp,-1,sizeof(dp));
//         int m = grid.size();
//         int n = grid[0].size();
//     int result =  solve(0,0,m,n,grid);
//     if(result<0){
//         return -1;
//     }
//     return result;
//     }
// };