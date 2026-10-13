class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>squares;
        int n = nums.size();
        for(int i=0;i<n;i++){
             squares.push_back(nums[i]*nums[i]);
        }
        sort(squares.begin(),squares.end());
        long long even = 0;
        long long odd =0;
        int i=0;
        while(i<n){
            if(i>=(n/2)){
                even+=squares[i];
            }
            else{
                odd+=squares[i];
            }
            i++;
        }
  long long result = even - odd;
        return result;

    }
};