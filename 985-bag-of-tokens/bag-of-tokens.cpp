
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n - 1;
        int count = 0, ans = 0;

        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                count++;
                ans = max(ans, count);
                i++;
            }
            else if (count > 0 && i < j) {
                power += tokens[j];
                count--;
                j--;
            }
            else {
                break;
            }
        }

        return ans;
    }
};