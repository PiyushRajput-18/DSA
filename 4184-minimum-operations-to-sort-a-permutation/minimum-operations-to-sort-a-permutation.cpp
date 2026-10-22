class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        while (nums[k] != 0) k++;

        int ans = INT_MAX;

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[(k + i) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(k, n - k + 2);
            if (k == 0) ans = 0;
        }

        vector<int> temp = nums;
        reverse(temp.begin(), temp.end());

        int j = n - 1 - k;
        ok = true;

        for (int i = 0; i < n; i++) {
            if (temp[(j + i) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, 1 + min(j, n - j));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};