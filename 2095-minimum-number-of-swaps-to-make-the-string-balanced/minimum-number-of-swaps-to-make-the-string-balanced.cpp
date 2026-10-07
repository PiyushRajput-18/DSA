class Solution {
public:
    int minSwaps(string s) {
      int n = s.length();
       stack<char>st;
      for(int i=0;i<n;i++){
       if(st.empty()){
           st.push(s[i]);
       }
      else if(st.top()=='['&&s[i]==']'){
        st.pop();
       }
       else{
        st.push(s[i]);
       }
      }
      if(st.size()==2){
        return 1;
      }
      if(st.empty()){
        return 0;
      }
      int x= st.size()/2;
     if(x%2!=0){
        return (x/2+1);
     }
     return (x/2);
    }
};