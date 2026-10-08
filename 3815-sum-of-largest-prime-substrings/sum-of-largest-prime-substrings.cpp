
class Solution {
public:
    bool isprime(long long n) {
        if (n < 2) return false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            long long val = 0;

            for (int j = i; j < n; j++) {
                val = val * 10 + (s[j] - '0');

                if (isprime(val)) {
                    st.insert(val);
                }
            }
        }
        vector<long long> v(st.begin(), st.end());
        sort(v.begin(), v.end());
        long long ans = 0;
        int count = 0;

        for (int i = (int)v.size() - 1; i >= 0 && count < 3; i--) {
            ans += v[i];
            count++;
        }
        return ans;
    }
};