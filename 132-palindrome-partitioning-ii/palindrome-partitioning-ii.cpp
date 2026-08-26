class Solution {
public:
// int dp[2001][2001];
// bool ispalindrome(int i, int j, string &s){
//     while(i<=j){
//         if(s[i]==s[j]){
//             i++;
//             j--;
//         }
//         else{
//             return false;
//         } 
//     }
//     return true;
// }
// int solve(int i, int j, string &s){
//     if(i>=j){
//         return 0;
//     }

//       if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     if(ispalindrome(i,j,s)){
//         return dp[i][j]=0;
//     }
  
//     int result=INT_MAX;
//     for(int k=i;k<=j-1;k++){
//         int ans = 1+ solve(i,k,s)+solve(k+1,j,s);
//         result = min(result,ans);
//     }
//     return dp[i][j]=result;
// }
//     int minCut(string s) {
//      memset(dp,-1,sizeof(dp));
//     int n = s.length();
//    int ans =  solve(0,n-1,s);
//    return ans;
      int minCut(string s) {
          int n = s.length();
          vector<vector<bool>>t(n,vector<bool>(n,false));


          for(int i=0;i<n;i++){
            t[i][i]=true;
          }


          for(int L=2;L<=n;L++){
            for(int i =0;i<n-L+1;i++){
                int j = i+L-1;

                if(L==2){
                    t[i][j]=(s[i]==s[j]);
                }
                else{
                    t[i][j]=((s[i]==s[j])&&(t[i+1][j-1]));
                }
            }
          }
          vector<int>dp(n);

          for(int i=0;i<n;i++){
            if(t[0][i]){
                dp[i]=0;
            }
            else{
                dp[i]=INT_MAX;
                for(int k=0;k<i;k++){
                    if(t[k+1][i]){
                        if(1+dp[k]<dp[i]){
                            dp[i]=1+dp[k];
                        }
                    }
                }
            }
          }
    return dp[n-1];
    }
};