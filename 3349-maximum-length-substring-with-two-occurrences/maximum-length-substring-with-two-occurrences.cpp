class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int>alpha(26,0);
        int i=0;
        int j=0;
        int ans =0;
        while(i<n&&j<n){
              
            if(alpha[s[j]-'a']<2){
                 alpha[s[j]-'a']++;
                j++;
                ans = max(ans,j-i);
            }
            else{
               
                alpha[s[i]-'a']--;
                 i++;
            }
        }
        return ans;
    }
};