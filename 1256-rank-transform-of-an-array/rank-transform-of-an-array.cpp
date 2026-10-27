class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
          int n = arr.size();
          vector<int> temp = arr;
    sort(temp.begin(),temp.end());
       unordered_map<int,int>mp;
          bool take = true;
         int k =1;
       for (int i = 0; i < n; i++) {
            if (i > 0 && temp[i] == temp[i - 1]) {
                continue;
            }
            mp[temp[i]] = k;
            k++;
        }
       vector<int>ans;
       for(int i=0;i<n;i++){
           ans.push_back(mp[arr[i]]);
       }
       return ans;
    }
};