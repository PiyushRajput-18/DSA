class Solution {
public:
int dp[501][501];
int solve(int i, int j, string &word1, string&word2){
    if(j>=word2.size()){
         if(i<=word1.size()){
            return (word1.size()-i);
         }
    }
     if(i>=word1.size()){
         if(j<=word2.size()){
            return (word2.size()-j);
         }
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // Same 
    if((i<word1.size()&&j<word2.size())&&(word1[i]==word2[j])){
       return solve(i+1,j+1,word1,word2);
    }
    int insert =0;
    int del =0;
    int replace =0;
    if((i<word1.size()&&j<word2.size())&&(word1[i]!=word2[j])){
        //insert
         insert = 1 + solve(i,j+1,word1,word2);
        // Delete
         del = 1 + solve(i+1,j,word1,word2);
        //replace 
         replace = 1 + solve(i+1,j+1,word1,word2);
    }
    return dp[i][j]=min({insert,del,replace});
   
}
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int result = solve(0,0,word1,word2);
        return result;
    }
};