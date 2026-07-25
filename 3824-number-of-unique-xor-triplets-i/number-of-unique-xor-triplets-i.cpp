class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        if(n==3){
            return n+1;
        }
    int bits = 0;

while(n > 0){
    bits++;
    n >>= 1;
}
int result = 1<<bits;
return result;
    }
};