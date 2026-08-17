class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        int i=0;
        int j=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    dp[i][j]=i+j;
                    }
                    else if(str1[i-1]==str2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=1+(min((dp[i][j-1]),(dp[i-1][j])));
                    }
            }
        }
        string result = "";

        int k=n;
        int l=m;
        while(k>0&&l>0){
            if(str1[k-1]==str2[l-1]){
                result.push_back(str1[k-1]);
                k--;
                l--;
            }else{
                if(dp[k-1][l]<dp[k][l-1]){
                    result.push_back(str1[k-1]);
                    k--;
                }
               else{
                    result.push_back(str2[l-1]);
                    l--;
                }
            }
        }

        while(k>0){
            result.push_back(str1[k-1]);
            k--;
        }
         while(l>0){
            result.push_back(str2[l-1]);
            l--;
        }
        reverse(result.begin(),result.end());
         return result;

    }
};