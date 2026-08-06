class Solution {
public:
int dp[1001][1001];
bool ispred(string &big, string &small) {

    if (big.size() != small.size() + 1)
        return false;

    int i = 0, j = 0;

    while (i < big.size()) {

        if (j < small.size() && big[i] == small[j]) {
            i++;
            j++;
        } else {
            i++;   
        }
    }

    return j == small.size();
}
int solve(int i, int p,vector<string>&words){
    if(i>=words.size()){
        return 0;
    }
    if(p!=-1&&dp[i][p]!=-1){
        return dp[i][p];
    }
    int take=0;
    if(p==-1||ispred(words[i],words[p])){
          take = 1+ solve(i+1,i,words);
    }
    int skip = solve(i+1,p,words);
    if(p!=-1){
        dp[i][p]=max(take,skip);
    }
    return max(take,skip);
}
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(), words.end(), [](string &a, string &b) {
        return a.length() < b.length();
        });
        return solve(0,-1,words);
    }
};