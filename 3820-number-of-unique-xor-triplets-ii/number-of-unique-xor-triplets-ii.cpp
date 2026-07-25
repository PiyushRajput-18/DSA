class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
         unordered_set<int>mpp;
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            mpp.insert( nums[i]^nums[j]);
            
        }
       }
       unordered_set<int>st;
       for(int i=0;i<n;i++){
          for(int it: mpp){
            st.insert(nums[i]^it);
          }
       }
       return st.size();
    }
};