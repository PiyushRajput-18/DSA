class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int result =-1;
        for(int i=0;i<n;i++){
            int sum =0;
              while(nums[i]>0){
                sum+= (nums[i]%10);
                nums[i]/=10;
              }
            if(sum==i){
                result=i;
                break;
            }
        }
        return result;
    }
};