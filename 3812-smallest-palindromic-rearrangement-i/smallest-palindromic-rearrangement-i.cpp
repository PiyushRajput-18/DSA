class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int m =0;
        if(n%2==0){
            m = n/2;
        }else{
            m=n/2;
        }
        string result(n,' ');
        for(int i=0;i<m;i++){
            result[i]=s[i];
        }
        sort(result.begin(),result.begin()+m);
        if(n%2==0){
           for(int i = 0;i<m;i++){
            result[m+i]=result[m-i-1];
           }
        }else{
            result[m]=s[m];
            for(int i=0;i<m;i++){
                result[m+i+1]=result[m-i-1];
            }
        }
        return result;

    }
};