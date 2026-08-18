class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    //   int n = nums.size();
    //   vector<int>temp(n,0);
    //   for(int i=0;i<n;i++){
    //     temp[i]=nums[i];
    //   }
    // sort(temp.begin(),temp.end());
    // int ans = -1;
    //   if(k==n){
    //     return temp[n-1];
    //   }
    //   else{
    //     for(int i=n-1;i>=0;i--){
    //         int app=0;
    //         for(int j=0;j<n;j++){
    //             if(temp[i]==nums[j]){
    //                 app++;
    //             }
    //             if(app==2){
    //                 break;
    //             }
    //         }
    //         if(app==1){
    //             ans = temp[i];
    //             break;
    //         }
         
    //     }
    //   }
    //   return ans;

     int n = nums.size();
    unordered_map<int,int>mpp;
   int i=0;
   int j = k-1;
   while(j<n){
    for(int l=i;l<=j;l++){
        mpp[nums[l]]++;
    }
    j++;
    i++;
   }

   int ans =-1;
   for(auto &it : mpp){
    if(it.second==1){
        ans = max(ans,it.first);
    }
   }
   if(k==n){
    return (*max_element(nums.begin(),nums.end()));
   }
   return ans;
        
    }
};