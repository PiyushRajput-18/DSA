class Solution {
public:
    long long price(long long n, int x) {
        long long ans = 0;

        for (int bit = x - 1; bit < 60; bit += x) {
            long long cycle = 1LL << (bit + 1);
            long long half = 1LL << bit;

            long long full = (n + 1) / cycle;
            long long rem = (n + 1) % cycle;

            ans += full * half;
            ans += max(0LL, rem - half);
        }

        return ans;
    }

    long long findMaximumNumber(long long k, int x) {
        long long lo = 0;
        long long hi = 1e15;

        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;

            if (price(mid, x) <= k)
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo;
    }
};