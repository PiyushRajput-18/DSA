class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) {
            return 0;
        }
        else if(n < 1000000) {
            return 1LL * (n - 1000 + 1);
        }
        else if(n < 1000000000) {
            long long ans1 = 1LL * (999999-1000 + 1);
            long long ans2 = 2LL * (n - 1000000 + 1);
            return ans1 + ans2;
        }
        else if(n < 1000000000000LL) {
            long long ans1 = 1LL * (999999 - 1000 + 1);
            long long ans2 = 2LL * (999999999- 1000000 + 1);
            long long ans3 = 3LL * (n - 1000000000LL + 1);
            return ans1 + ans2 + ans3;
        }
        else if(n < 1000000000000000LL) {
            long long ans1 = 1LL * (999999 - 1000 + 1);
            long long ans2 = 2LL * (999999999 - 1000000 + 1);
            long long ans3 = 3LL * (999999999999 - 1000000000LL + 1);
            long long ans4 = 4LL * (n - 1000000000000LL + 1);
            return ans1 + ans2 + ans3 + ans4;
        }
        else {
            long long ans1 = 1LL * (999999 - 1000 + 1);
            long long ans2 = 2LL * (999999999 - 1000000 + 1);
            long long ans3 = 3LL * (999999999999 - 1000000000LL + 1);
            long long ans4 = 4LL * (999999999999999 - 1000000000000LL + 1);
            long long ans5 = 5LL * (n - 1000000000000000LL + 1);

            return ans1 + ans2 + ans3 + ans4 + ans5;
        }
    }
};