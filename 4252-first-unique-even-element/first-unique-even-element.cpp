class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int result =-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                if(mpp[nums[i]]==1){
                    result = nums[i];
                    return result;
                }
            }
        }
        return result;
    }
};