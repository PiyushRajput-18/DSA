class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int>prefix(n+1);
       unordered_map<int,int>mpp;
       prefix[0]=0;                                              
       for(int i=1;i<=n;i++){
          prefix[i]=prefix[i-1]+nums[i-1];
       } 
       for(int i=0;i<=n;i++){
        mpp[((prefix[i]%k)+k)%k]++;
       }
       long long count =0;
       for(auto &it: mpp){
          int x =it.second;
          count+= (x*(x-1))/2;
       }
       return count;
    }
};