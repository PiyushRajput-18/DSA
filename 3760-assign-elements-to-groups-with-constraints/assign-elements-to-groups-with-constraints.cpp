class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        int m = elements.size();

        unordered_map<int, vector<int>> mpp;

      for(int i = 0; i < n; i++) {

    if(mpp.find(groups[i]) != mpp.end())
        continue;
       for(int j = 1; j * j <= groups[i]; j++) {
        if(groups[i] % j == 0) {
            mpp[groups[i]].push_back(j);
          if(j != groups[i] / j)
                mpp[groups[i]].push_back(groups[i] / j);
        }
    }
}
      unordered_map<int, int> elementMap;
        for(int i = 0; i < m; i++) {
            if(elementMap.find(elements[i]) == elementMap.end()) {
                elementMap[elements[i]] = i;
            }
        }
        vector<int> assigned(n, -1);

        for(int j = 0; j < n; j++) {

            int best = INT_MAX;
            for(int x : mpp[groups[j]]) {

                if(elementMap.find(x) != elementMap.end()) {
                    best = min(best, elementMap[x]);
                }
            }
            if(best != INT_MAX) {
                assigned[j] = best;
            }
        }
        return assigned;
    }
};
