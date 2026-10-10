class Solution {
public:
    int minInsertions(string s) {
      int n = s.length();
      int result =0;
      stack<char>st;
      int i=0;
      while(i<n){
        if(s[i]=='('){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(st.top()=='('){
            st.push('(');
        }
        else if(st.top()==')'){
            result++;
            st.pop();
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
            st.push(s[i]);
        }
        }
        else{
            if(st.empty()){
                result++;
                st.push(s[i]);
            }
            else if(st.top()==')'){
                 st.pop();
                if(!st.empty()&&st.top()=='('){
                    st.pop();
                }
            }
            else if(st.top()=='('){
                st.push(s[i]);
            }
        }
        i++;
      }  
      int opencount =0;
      int closecount=0;
      while(!st.empty()){
        if(st.top()=='('){
            opencount++;
        }else{
            closecount++;
        }
        st.pop();
      }
      if(opencount==0&&closecount==1){
        result+=2;
      }
      result+=(2*opencount-closecount);
      return result;
    }
};