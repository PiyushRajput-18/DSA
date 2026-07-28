class Solution {
public:
    int titleToNumber(string columnTitle) {
       int n = columnTitle.size();
       long long result=0;
       int i=0;
       
       while(n>0){
        
           result +=pow(26,n-1)*(columnTitle[i]-'A'+1);
           i++;
           n--;
           
       }
       return result;
    }
};