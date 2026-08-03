class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long mod = 1e9+7;
        long long tn = (n*(n+1))/2;
        int k = nums.size();
        int l=0;
        vector<long long>temp(tn,0);
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum +=nums[j];
                 if(l<tn){
                    temp[l]=sum;
                    l++;
                    }  
            }
        }
        sort(temp.begin(),temp.end());
        long long result =0;
        for(int i=left-1;i<right;i++){
            result = (result+temp[i])%mod;
        }
        return result;
    }
};