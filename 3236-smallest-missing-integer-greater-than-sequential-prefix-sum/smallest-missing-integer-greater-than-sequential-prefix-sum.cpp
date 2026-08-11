class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int result =0;
        int sum =nums[0];
       
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum = sum+ nums[i];
                  
            }
            else{
                break;
            }
        }
       unordered_set<int>st;
      sort(nums.begin(),nums.end());
      for(int i=0;i<n;i++){
        st.insert(nums[i]);
      }

while(st.count(sum)){
    sum++;
}

return sum;
        
    }
};