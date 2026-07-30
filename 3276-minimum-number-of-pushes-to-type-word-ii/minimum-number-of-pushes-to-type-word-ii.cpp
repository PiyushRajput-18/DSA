class Solution {
public:
    int minimumPushes(string word) {
   vector<int>num(26,0);
    int n= word.size();
    int result=0;
    for(int i=0;i<n;i++){
        num[word[i]-'a']++;
    }
    sort(num.begin(), num.end(), greater<int>());
    int k = num.size();
    
    for(int i=0;i<k;i++){
        if(i<8){
        result+=(num[i]);
        }
       else if(i<16){
        result+=num[i]*2;
       }
       else if(i<24){
        result+=num[i]*3;
       }
       else{
        result+=num[i]*4;
       }
    }
    
     
    return result;
      
    }
};