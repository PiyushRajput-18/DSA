class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
            prefix[i+1]=prefix[i]+1;
            }else{
               prefix[i+1]=prefix[i]-1; 
            }
        }
        unordered_map<int,int>mpp;
        mpp[0]=0;
        int count =0;
        for(int i=1;i<=n;i++){
            if(mpp.find(prefix[i])==mpp.end()){
                mpp[prefix[i]]=i;
            }else{
                count = max(count,i-mpp[prefix[i]]);
            }
        }
        return count;
    }
};  