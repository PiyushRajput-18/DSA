class Solution {
public:
bool check(int i, int j, string &st,vector<vector<bool>>& dp){
         if(i >= j) {
            return true;
        }

        if(dp[i][j] != false) {
            return dp[i][j];
        }

        if(st[i] == st[j]) {
            return dp[i][j] = check(i + 1, j - 1, st, dp);
        }

        return dp[i][j] = false;
}
    string longestPalindrome(string s) {
     int n = s.length();
     int maxlength =0;
        vector<vector<bool>> dp(1001, vector<bool>(1001, false));
     int sp=0;
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(check(i,j,s,dp)){
               if((j-i+1)>maxlength){
                maxlength=j-i+1;
                sp=i;
               }
            }
        }
     }
     return s.substr(sp,maxlength);
    }
};