class Solution {
public:
    bool isValid(string s) {
       int n = s.length();
       stack<char>st;
      int i=0;
       int a=0;
       int b=0;
       int c=0;
       for(int i=0;i<n;i++){
        if(s[i]=='a'){
            a++;
        }
        else if(s[i]=='b'){
            b++;
        }else{
            c++;
        }
       }
       if(a!=b||a!=c||b!=c){
        return false;
       }
       int count =0;
       while(i<n){
        if(s[i]=='a'||s[i]=='b'){
            st.push(s[i]);
        }else{
            int rem =0;
            int j=0;
            bool ask = false;
            while(j<2){
            if(!st.empty()&&st.top()=='b'){
                  st.pop();
                  rem++;
                ask=true;
            } 
           else if(ask){
                if(!st.empty()&&st.top()=='a'){
                    st.pop();
                    rem++;
                }
            }
            j++;
            }
            if(rem==2){
                count++;
            }
            if(count==a){
                return true;
            }
        }
        i++;
       } 
       return false;
    }
};