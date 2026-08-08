class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();

        vector<long long>v;
        for(int i=0;i<n;i++){
            v.push_back((long long)nums[i]-i);
        }

        vector<long long>temp=v;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        int m=temp.size();
        vector<long long>bit(m+2,LLONG_MIN);

        auto update=[&](int i,long long val){
            while(i<=m){
                bit[i]=max(bit[i],val);
                i+=i&-i;
            }
        };

        auto query=[&](int i){
            long long ans=LLONG_MIN;
            while(i>0){
                ans=max(ans,bit[i]);
                i-=i&-i;
            }
            return ans;
        };

        long long ans=LLONG_MIN;

        for(int i=0;i<n;i++){
            int id=lower_bound(temp.begin(),temp.end(),v[i])-temp.begin()+1;

            long long best=query(id);
            long long cur=nums[i];

            if(best!=LLONG_MIN){
                cur=max(cur,best+nums[i]);
            }

            ans=max(ans,cur);
            update(id,cur);
        }

        return ans;
    }
};