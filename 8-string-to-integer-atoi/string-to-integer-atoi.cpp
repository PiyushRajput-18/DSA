class Solution {
public:
    int myAtoi(string s) {
      int n = s.length();
      string st="";
      int digit =0;
      int k=0;
      while(k<n){
        if(s[k]==' '){
            k++;
        }else{
            break;
        }
      }
      int sign = 1;
        if (k < n && (s[k] == '+' || s[k] == '-')) {
        if (s[k] == '-') {
            sign = -1;
            }
            k++;
        }
      for(int i=k;i<n;i++){
         if(digit ==1 ){
            break;
         }
      if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]  =='7'||s[i]=='8'||s[i]=='9'){
             st=st+s[i];
         }
         else{
            digit=1;
         }
      }
      if(st.empty()){
        return 0;
      }
      long long result =0;
      int x = st.length();
      for(int i=0;i<st.length();i++){
        int dig = st[i]-'0';
           result = result*10+dig;
           if (sign * result >= INT_MAX) return INT_MAX;
      if (sign * result <= INT_MIN) return INT_MIN;
      }
      
      return result*sign;
    }
};