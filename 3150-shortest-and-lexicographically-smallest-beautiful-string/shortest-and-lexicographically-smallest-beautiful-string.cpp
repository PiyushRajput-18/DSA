class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int len = 0;
        int i = 0;
        int j = 0;
        int cnt = 0;

        while(j < n) {
             
            if(s[j] == '1'){
                cnt++;
            }

            if(cnt < k){
                j++;
            }

            else if(cnt == k){

                while(i < j && s[i] == '0'){
                    i++;
                }

                if(ans.empty()){
                    ans = s.substr(i, j-i+1);
                    len = j-i+1;
                }
                else{
                    if(len > j-i+1){
                        ans = s.substr(i, j-i+1);
                        len = j-i+1;
                    }
                    else if(len == j-i+1){

                        int m = 0;
                        int l = i;

                        while(m < ans.length() && l <= j){

                            if(ans[m] == '1' && s[l] == '0'){
                                ans = s.substr(i, j-i+1);
                                break;
                            }
                            else if(ans[m] == '0' && s[l] == '1'){
                                break;
                            }

                            m++;
                            l++;
                        }
                    }
                }

                j++;
            }

            else if(cnt > k){

                if(s[i] == '1'){
                    cnt--;
                }

                i++;
                while(cnt > k){
                    if(s[i] == '1'){
                        cnt--;
                    }
                    i++;
                }

                while(i < j && s[i] == '0'){
                    i++;
                }

                if(len > j-i+1){
                    ans = s.substr(i, j-i+1);
                    len = j-i+1;
                }
                else if(len == j-i+1){
                    int m = 0;
                    int l = i;

                    while(m < ans.length() && l <= j){

                        if(ans[m] == '1' && s[l] == '0'){
                            ans = s.substr(i, j-i+1);
                            break;
                        }
                        else if(ans[m] == '0' && s[l] == '1'){
                            break;
                        }

                        m++;
                        l++;
                    }
                }

                j++;
            }
        }

        return ans;
    }
};