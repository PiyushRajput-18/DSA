class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int result = 0;
        int count = 0;
        int i = 0;
        int j = 0;
        int n = word.length();
        char prev = 'z';

        while (j < n) {

            if (prev == 'z') {
                if (word[j] == 'a') {
                    i = j;
                    count = 1;
                    prev = 'a';
                    j++;
                }
                else {
                    j++;
                }
            }

            else if (prev == 'a') {
                if (word[j] == 'a' || word[j] == 'e') {

                    if (word[j] == 'e') {
                        count++;
                    }

                    prev = word[j];
                    j++;
                }
                else {
                    if (word[j] == 'a') {
                        i = j;
                        count = 1;
                        prev = 'a';
                        j++;
                    }
                    else {
                        count = 0;
                        i = j + 1;
                        j++;
                        prev = 'z';
                    }
                }
            }

            else if (prev == 'e') {
                if (word[j] == 'e' || word[j] == 'i') {

                    if (word[j] == 'i') {
                        count++;
                    }

                    prev = word[j];
                    j++;
                }
                else {
                    if (word[j] == 'a') {
                        i = j;
                        count = 1;
                        prev = 'a';
                        j++;
                    }
                    else {
                        count = 0;
                        i = j + 1;
                        j++;
                        prev = 'z';
                    }
                }
            }

            else if (prev == 'i') {
                if (word[j] == 'i' || word[j] == 'o') {

                    if (word[j] == 'o') {
                        count++;
                    }

                    prev = word[j];
                    j++;
                }
                else {
                    if (word[j] == 'a') {
                        i = j;
                        count = 1;
                        prev = 'a';
                        j++;
                    }
                    else {
                        count = 0;
                        i = j + 1;
                        j++;
                        prev = 'z';
                    }
                }
            }

            else if (prev == 'o') {
                if (word[j] == 'o' || word[j] == 'u') {

                    if (word[j] == 'u') {
                        count++;
                    }

                    prev = word[j];
                    j++;
                }
                else {
                    if (word[j] == 'a') {
                        i = j;
                        count = 1;
                        prev = 'a';
                        j++;
                    }
                    else {
                        count = 0;
                        i = j + 1;
                        j++;
                        prev = 'z';
                    }
                }
            }

            else if (prev == 'u') {
                if (word[j] == 'u') {
                    j++;
                }
                else {
                    if (count == 5) {
                        result = max(result, j - i);
                    }

                    if (word[j] == 'a') {
                        i = j;
                        count = 1;
                        prev = 'a';
                        j++;
                    }
                    else {
                        count = 0;
                        i = j + 1;
                        j++;
                        prev = 'z';
                    }
                }
            }

            if (count == 5) {
                result = max(result, j - i);
            }
        }

        return result;
    }
};