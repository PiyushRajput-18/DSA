class Solution {
public:
    string frequencySort(string s) {
        int n= s.length();
    unordered_map<char,int> freq;
for(char ch : s){
    freq[ch]++;
}
map<int, vector<char>> mpp;

for(auto &it : freq){
    mpp[it.second].push_back(it.first);
}
    string result = "";

for (auto &it : mpp) {
    for (char ch : it.second) {
       result.append(it.first, ch);
    }
}

   reverse(result.begin(),result.end());
   return result;    
    }
};