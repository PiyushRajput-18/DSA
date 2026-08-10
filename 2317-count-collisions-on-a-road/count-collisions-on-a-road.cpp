class Solution {
public:
    int countCollisions(string d) {
        // int n = d.size();
        // stack<char>st;
        // int coll=0;
        // int j=0;
        // int i=0;
        
        // while(j<n){
           
        //      if(d[j]=='S'||d[j]=='R'){
        //         st.push(d[j]);
        //         if(j+1<n){
        //             i=j+1;
        //         }else{
        //             return 0;
        //         }
            
        //         break;
              
        //       }
              
        //     j++;
        // }
        // while(i<n){
        //     if(!st.empty()&&st.top()=='R'){
        //         if(d[i]=='L'){

        //             coll+=2;
        //             st.pop();
        //             while(!st.empty()&&st.top()=='R'){
        //                 coll++;
        //                 st.pop();
        //             }
        //            st.push('S');
        //         }
        //         else if(d[i]=='S'){
        //             coll++;
        //             st.pop();
        //             st.push('S');
        //         }
        //         else{
        //             st.push('R');
        //         }
        //     }
        //     else if(!st.empty()&&st.top()=='S'){
        //         if(d[i]=='R'){
        //             st.pop();
        //             st.push('R');
        //         }
        //         else if(d[i]=='L'){
        //             coll++;
        //         }
        //     }
        //     i++;
        // }
        // return coll;

   int n = d.size();
        stack<char>st;
        int coll=0;
        int j=0;
        int i=0;
        
        while(j<n){
           
             if(d[j]=='S'||d[j]=='R'){
                st.push(d[j]);
                if(j+1<n){
                    i=j+1;
                }else{
                    return 0;
                }
            
                break;
              
              }
              
            j++;
        }

   while(i<n){
       if(!st.empty()&&st.top()=='R'){
             if(d[i]=='R'){
                st.push('R');
             }
             else if(d[i]=='S'){
                   coll++;
                   st.pop();
                    while(!st.empty()&&st.top()=='R'){
                        coll++;
                        st.pop();
                }
                   st.push('S');
             }
             else{
                coll+=2;
                st.pop();
                
                while(!st.empty()&&st.top()=='R'){
                        coll++;
                        st.pop();
                }
                st.push('S');
             }
       }
       else if(!st.empty()&&st.top()=='S'){
            if(d[i]=='S'){
                st.push('S');
            }
            else if(d[i]=='R'){
                st.push('R');
            }
            else{
                
                coll++;
            }
       }
       i++;
   }
   return coll;
    }
};