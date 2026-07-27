class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // long long result =0;
        // int n = nums.size();
        // int firstlargest = 0;
        // bool large = true;
        // int secondsmallest = 0;
        // bool small = false;
        // int thirdlargest=0;
        // for(int i=0;i<n;i++){
          
        //     if(nums[i]>firstlargest&&large){
        //         firstlargest = nums[i];
        //         secondsmallest=nums[i];
        //     }
        //     if(nums[i]<firstlargest){
        //             secondsmallest = min(nums[i],secondsmallest);
                 
        //            large = false;
                    
        //     }
        //  if((nums[i]>secondsmallest&&!large)||(nums[i]>firstlargest&&!large)){
        //      thirdlargest = nums[i];
        //     thirdlargest = max(thirdlargest,nums[i]);
               
        //     }
        // }
        // result = (firstlargest-secondsmallest)*1LL*thirdlargest;
        // return result;
        int n = nums.size();
    vector<int>prefix(n,0);
    prefix[0]=nums[0];
    vector<int>suffix(n,0);
    suffix[n-1]=nums[n-1];
    for(int i=1;i<n;i++){
        prefix[i]=max(nums[i-1],prefix[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(nums[i+1],suffix[i+1]);
    }
    long long ans=0;
    for(int i=1;i<n-1;i++){
        ans = max(ans,(prefix[i]-nums[i])*1LL*suffix[i]);
    }
    return ans;
    }
};  
