class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return *max_element(nums.begin(),nums.end());
        }
       
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    if(mpp.size()<3){
        return *max_element(nums.begin(),nums.end());
    }
    sort(nums.begin(),nums.end());
   int unique = 1;

for(int i = n-2; i >= 0; i--){
    if(nums[i] == nums[i+1])
        continue;

    unique++;

    if(unique == 3)
        return nums[i];
}

return nums[n-1];
   
    }
};