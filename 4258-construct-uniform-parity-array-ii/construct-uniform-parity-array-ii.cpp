class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int smallodd=INT_MAX;
        int evencount =0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0){
                smallodd = min(smallodd,nums1[i]);
            }
            else{
                evencount++;
            }
        }
        if(smallodd==INT_MAX){
            smallodd=0;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                if(nums1[i]-smallodd>=1){
                    count++;
                }
            }
        }
        if(count==evencount){
            return true;
        }
        return false;
    }
};