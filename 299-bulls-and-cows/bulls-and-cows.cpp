class Solution {
public:
    string getHint(string s, string g) {
         int n = s.length();
         unordered_map<char,int>mpp;
          int bulls=0;
         for(int i=0;i<n;i++){
            if(s[i]==g[i]){
                bulls++;
            }else{
               mpp[s[i]]++;
            }
         }
        int i=0;
       
        int cows=0;
        while(i<n){
              if(s[i] != g[i] && mpp[g[i]] > 0){
              cows++;
               mpp[g[i]]--;
             }
            
            i++;
        }
        string result="";
        result += to_string(bulls);
        result+="A";
        result += to_string(cows);
        result+="B";
        return result;
       
    }
};