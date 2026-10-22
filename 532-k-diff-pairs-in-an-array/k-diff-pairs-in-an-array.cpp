class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int result=0;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n-1;i++){
         if (i > 0 && nums[i] == nums[i - 1])
                continue;
        int left = i+1;
        int right = n-1;
        int mid = (left+right)/2;
        while(left<=right){
            if(abs(nums[mid]-nums[i])>k){
                right=mid-1;
            }
            else if(abs(nums[i]-nums[mid])<k){
                left=mid+1;
            }
            else{
                result++;
                break;
            }
            mid = (left+right)/2;
        }
       }
       return result;
    }
};