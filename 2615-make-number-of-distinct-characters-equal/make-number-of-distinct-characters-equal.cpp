class Solution {
public:
    int distinct(vector<int> &freq){
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0) cnt++;
        }
        return cnt;
    }

    bool isItPossible(string word1, string word2) {

        vector<int> w1(26,0), w2(26,0);

        for(char ch : word1) w1[ch-'a']++;
        for(char ch : word2) w2[ch-'a']++;

        for(int i = 0; i < 26; i++){

            if(w1[i] == 0) continue;

            for(int j = 0; j < 26; j++){

                if(w2[j] == 0) continue;
                w1[i]--;
                w2[j]--;

                w1[j]++;
                w2[i]++;

                if(distinct(w1) == distinct(w2))
                    return true;

         
                w1[j]--;
                w2[i]--;

                w1[i]++;
                w2[j]++;
            }
        }

        return false;
    }
};