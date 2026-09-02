class Solution {
public:
    long long flowerGame(int n, int m) {
       long long oddn =0;
       long long evenn=0;
       long long oddm=0;
       long long evenm=0;
       for(int i=1;i<=n;i++){
        if(i%2==0){
            evenn++;
        }
        else{
            oddn++;
        }
       } 
        for(int i=1;i<=m;i++){
        if(i%2==0){
            evenm++;
        }
        else{
            oddm++;
        }
       }
       long long result =1;
       result = (1LL*oddn*evenm)+(1LL*evenn*oddm);
       return result;
    }
};