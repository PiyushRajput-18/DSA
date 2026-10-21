class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        vector<int>store;
        for(int i=0;i<n;i++){
            store.push_back(s[i]-'a');
        }   
        int x =store[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(store[i]>=x){
                x=store[i];
                count++;
            }
        }
        if(count==n){
            return 0;
        }
        if(n==2){
            return -1;
        }


        int smallest= *min_element(store.begin(),store.end());
        int largest = *max_element(store.begin(),store.end());
        if(smallest==store[0]||largest==store[n-1]){
            return 1;
        }

          int largecount=0;
        int smallcount=0;
        for(int i=0;i<n;i++){
               if(smallest==store[i]){
                smallcount++;
               }
               else if(largest==store[i]){
                largecount++;
               }
        }
        if(largest==store[0]&&smallest==store[n-1]){
            if(largecount==1&&smallcount==1){
                return 3;
            }
        }
        return 2;
    }
};