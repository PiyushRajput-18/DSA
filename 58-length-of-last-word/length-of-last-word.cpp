class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i=n-1;
        for(i;i>=0;i--){
            if(s[i]==' '){
                continue;
            }
            break;
        }
        int result=0;
        for(i;i>=0;i--){
            if(s[i]!=' '){
                result++;
                continue;
            }
            break;
        }
        return result;
    }
};