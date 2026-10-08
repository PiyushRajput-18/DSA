class Solution {
public:
    string removeOuterParentheses(string s) {
          int n = s.length();
             string output="";
              int i=0;
              int open =0;
              bool take = true;
              while(i<n){
                  if(s[i]=='('){
                    open++;
                    if(open==1){
                        take = false;
                    }
                  } 
                 if(s[i]==')'){
                    open--;
                    if(open==0){
                        take= false;
                    }
                  }
               
               
                  if(take){
                  output+=s[i];
                  }
                  take = true;
                  i++;
              }
             return output;

    }
};