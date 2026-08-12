class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        vector<vector<int>> alpha(26);
        for (int i = 0; i < s.length(); i++) {
            alpha[s[i] - 'a'].push_back(i);
        }
       int result = 0;

        for (int j = 0; j < words.size(); j++) {
            string temp = words[j];
            int less = -1;
            bool let = true;
            for (int k = 0; k < temp.length(); k++) {
                char ch = temp[k];

                auto it = upper_bound(
                    alpha[ch - 'a'].begin(),
                    alpha[ch - 'a'].end(),
                    less
                );
                if (it == alpha[ch - 'a'].end()) {
                    let = false;
                    break;
                }

                less = *it;
            }

            if (let) {
                result++;
            }
        }

        return result;
    }
};